# WsGetReaderProperty function

## Description

This function returns a property of the specified XML Reader.

**Note** Obtaining the Property **WS_XML_READER_PROPERTY_CHARSET** will require inspecting up to the first
four bytes of the XML data. Consequently if the Reader is using [WS_XML_READER_STREAM_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_stream_input) the
[WsFillReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfillreader) function must be called first to ensure that this data has been read.

## Parameters

### `reader` [in]

A pointer to a WS_XML_READER object containing the desired property value.

### `id` [in]

An enumerator value identifier of the Reader property.

### `value`

A pointer to the address for returning the retrieved value.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

A byte count of the buffer that the caller has allocated for the retrieved value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |