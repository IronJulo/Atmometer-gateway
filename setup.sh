#!/bin/bash

set -e

cd EmbeddedProto
python3 setup.py
cd ..

mkdir -p Firmware/lib/embeddedproto

cp EmbeddedProto/src/* Firmware/lib/embeddedproto

protoc --plugin=protoc-gen-eams=./EmbeddedProto/protoc-gen-eams -I ./ --eams_out=./Firmware/lib/protocol protocol.proto
