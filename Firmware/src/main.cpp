#include <Arduino.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "LoRa.h"
#include "protocol.h"
#include <WriteBufferFixedSize.h>
#include <ReadBufferFixedSize.h>

const double FREQUENCY = 433E6;
const double BANDWIDTH = 125E3;
const int SPREADING_FACTOR = 7;
const int CODING_RATE_DENOM = 8;
const int PREAMBLE_LENGTH = 8;

const int LORA_SCK = 3;
const int LORA_MISO = 7;
const int LORA_MOSI = 6;
const int LORA_SS = 2;
const int LORA_RST = 0;
const int LORA_DIO0 = 1;

#define SOCKET_LAYOUT_PACKET_ID 0x01
#define DATA_PACKET_ID 0x02

uint16_t computeCRC(uint8_t *data, uint8_t length);
uint8_t sendSocketLayoutPacket();
uint8_t sendDataPacket();
void printSocketLayoutPacket(com::epitech::atmos::protobuf::Socket_layout_packet<64> &socketLayoutPacket);
void printDataPacket(com::epitech::atmos::protobuf::Data_packet<64> &dataPacket);
void onReceive(int packetSize);

com::epitech::atmos::protobuf::Socket_layout_packet<64> socketLayoutPacket;
com::epitech::atmos::protobuf::Data_packet<64> dataPacket;

#define LORA_BUFFER_SIZE 256
EmbeddedProto::WriteBufferFixedSize<LORA_BUFFER_SIZE> writeBuffer;
EmbeddedProto::ReadBufferFixedSize<LORA_BUFFER_SIZE> readBuffer;

uint8_t loraRXBuffer[LORA_BUFFER_SIZE];
bool packetReceived = false;

void setup()
{
	Serial.begin(9600);
	Serial.println("Atmometer gateway starting...");

	LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
	if (!LoRa.begin(FREQUENCY))
	{
		Serial.println("Starting LoRa failed!");
		while (1)
			;
	}
	LoRa.setSignalBandwidth(BANDWIDTH);
	LoRa.setSpreadingFactor(SPREADING_FACTOR);
	LoRa.setCodingRate4(CODING_RATE_DENOM);
	LoRa.onReceive(onReceive);
	LoRa.receive();
	delay(1000);
}

void printBinary(uint8_t value)
{
	for (int i = 7; i >= 0; i--)
	{
		Serial.print((static_cast<unsigned long long>(value) >> i) & 1);
	}
}

void loop()
{
	Serial.println("waiting");
	if (packetReceived)
	{
		uint16_t packetID = 0;
		packetID |= (uint16_t)loraRXBuffer[0] << 8;
		packetID |= (uint16_t)loraRXBuffer[1] << 0;
		printBinary(loraRXBuffer[0]);
		Serial.print(" ");
		printBinary(loraRXBuffer[1]);
		Serial.print(" ");
		for (uint8_t i = 2; i < LORA_BUFFER_SIZE - 2; i++)
		{
			readBuffer.set_bytes_written(0);
			readBuffer.get_data()[i] = loraRXBuffer[i];
			printBinary(loraRXBuffer[i]);
			Serial.print(" ");
		}
		Serial.println("");
		Serial.println("");
		switch (packetID)
		{
		case SOCKET_LAYOUT_PACKET_ID:
			Serial.println("socket layout packet received");
			socketLayoutPacket.deserialize(readBuffer);
			printSocketLayoutPacket(socketLayoutPacket);
			break;
		case DATA_PACKET_ID:
			Serial.println("data packet received");
			dataPacket.deserialize(readBuffer);
			printDataPacket(dataPacket);
			break;

		default:
			Serial.print("Unknown packet ID: ");
			Serial.println(packetID);
			break;
		}
		packetReceived = false;
	}
	delay(2000);
}

uint16_t computeCRC(uint8_t *data, uint8_t length)
{
	uint8_t crc = 0;

	for (uint8_t i = 0; i < length; i++)
	{
		crc += data[i];
	}

	return crc;
}

uint8_t sendSocketLayoutPacket()
{
	return 0;
}

uint8_t sendDataPacket()
{
	return 0;
}

void printSocketLayoutPacket(com::epitech::atmos::protobuf::Socket_layout_packet<64> &socketLayoutPacket)
{
	const int rows = 1; // 4;
	const int cols = 3;
	const int cellWidth = 20;
	int col = 0;

	std::ostringstream oss;
	oss << "+---------------+\n";
	oss << "|               |\n";
	oss << "|Device ID: " << std::setw(4) << std::left << static_cast<unsigned long long>(socketLayoutPacket.header().device_id()) << "|\n";
	oss << "|Packet CRC: " << std::setw(3) << std::left << static_cast<unsigned long long>(socketLayoutPacket.header().packet_crc()) << "|\n";
	oss << "+---------------+---------------+---------------+\n";

	for (int row = 0; row < rows; ++row)
	{
		oss << "|               |               |               |\n";
		oss << "|               |               |               |\n";
		oss << "|SoID: " << std::setw(9) << std::left << (col * cols) + 0;
		oss << "|SoID: " << std::setw(9) << std::left << (col * cols) + 1;
		oss << "|SoID: " << std::setw(9) << std::left << (col * cols) + 2;
		oss << "|\n";
		oss << "|Type: " << std::setw(9) << std::left << static_cast<unsigned long long>(socketLayoutPacket.mutable_socket_data()[(col * cols) + 0].get_sensor_type());
		oss << "|Type: " << std::setw(9) << std::left << static_cast<unsigned long long>(socketLayoutPacket.mutable_socket_data()[(col * cols) + 1].get_sensor_type());
		oss << "|Type: " << std::setw(9) << std::left << static_cast<unsigned long long>(socketLayoutPacket.mutable_socket_data()[(col * cols) + 2].get_sensor_type());
		oss << "|\n";
		oss << "|ID: " << std::setw(11) << std::left << static_cast<unsigned long long>(socketLayoutPacket.mutable_socket_data()[(col * cols) + 0].get_sensor_id());
		oss << "|ID: " << std::setw(11) << std::left << static_cast<unsigned long long>(socketLayoutPacket.mutable_socket_data()[(col * cols) + 1].get_sensor_id());
		oss << "|ID: " << std::setw(11) << std::left << static_cast<unsigned long long>(socketLayoutPacket.mutable_socket_data()[(col * cols) + 2].get_sensor_id());
		oss << "|\n";
		oss << "+---------------+---------------+---------------+\n";
		col++;
	}

	Serial.println(oss.str().c_str());
}

void printDataPacket(com::epitech::atmos::protobuf::Data_packet<64> &dataPacket)
{
	const int rows = 1; // 4;
	const int cols = 3;
	int col = 0;
	const int cellWidth = 20;

	std::ostringstream oss;
	oss << "+---------------+\n";
	oss << "|               |\n";
	oss << "|Device ID: " << std::setw(4) << std::left << static_cast<unsigned long long>(dataPacket.header().device_id()) << "|\n";
	oss << "|Packet CRC: " << std::setw(2) << std::left << static_cast<unsigned long long>(dataPacket.header().packet_crc()) << "|\n";
	oss << "+---------------+---------------+---------------+\n";

	for (int row = 0; row < rows; ++row)
	{
		oss << "|               |               |               |\n";
		oss << "|               |               |               |\n";
		oss << "|SoID: " << std::setw(9) << std::left << (col * cols) + 0;
		oss << "|SoID: " << std::setw(9) << std::left << (col * cols) + 1;
		oss << "|SoID: " << std::setw(9) << std::left << (col * cols) + 2;
		oss << "|\n";
		oss << "|Val : " << std::setw(9) << std::left << static_cast<unsigned long long>(dataPacket.sensor_data()[(col * cols) + 0]);
		oss << "|Val : " << std::setw(9) << std::left << static_cast<unsigned long long>(dataPacket.sensor_data()[(col * cols) + 1]);
		oss << "|Val : " << std::setw(9) << std::left << static_cast<unsigned long long>(dataPacket.sensor_data()[(col * cols) + 2]);
		oss << "|\n";
		oss << "+---------------+---------------+---------------+\n";
		col++;
	}

	Serial.println(oss.str().c_str());
}

void onReceive(int packetSize)
{
	Serial.print("Received packet");
	if (packetReceived)
	{
		for (int i = 0; i < packetSize; i++)
		{
			(char)LoRa.read();
		}
		return;
	}
	else
	{
		packetReceived = true;
		for (int i = 0; i < packetSize; i++)
		{
			loraRXBuffer[i] = LoRa.read();
		}
	}

	Serial.print(" with RSSI ");
	Serial.println(LoRa.packetRssi());
}