# WS_XML_READER_STREAM_INPUT structure

## Description

Specifies that the source of the xml should be obtained from a callback.

## Members

### `input`

The base type for all types that derive from [WS_XML_READER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_input).

### `readCallback`

A callback that is invoked when [WsFillReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfillreader) is called.

### `readCallbackState`

A user-defined value that will be passed back to readCallback.