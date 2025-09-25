# WS_XML_READER_BUFFER_INPUT structure

## Description

Specifies that the source of the xml input is a buffer.

## Members

### `input`

The base type for all types that derive from [WS_XML_READER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_input).

### `encodedData`

A pointer to the bytes of data that comprise the encoded form of the xml. The reader will not modify any of these bytes.

### `encodedDataSize`

The length of the encodedData.