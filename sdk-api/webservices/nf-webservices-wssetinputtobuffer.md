# WsSetInputToBuffer function

## Description

Sets Reader input to a specified XML buffer.
Reader properties
specified to **WsSetInputToBuffer** override properties set by [WsCreateReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatereader).

The reader does not modify [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) input data.

**Note** It is permissible for more than one reader to read from the same **WS_XML_BUFFER**.

## Parameters

### `reader` [in]

A pointer to the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object for which the input will be set.

### `buffer` [in]

A pointer to the XML buffer to read.

### `properties`

A pointer that references an array of optional Reader properties.

**Note** For more information see [WS_XML_READER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_property).

.

### `propertyCount` [in]

The number of properties.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When an XML Reader has an XML Buffer as an input source, the Reader can be used in a random access fashion, and
the functions [WsGetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetreaderposition), [WsSetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetreaderposition), and [WsMoveReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovereader) are available for use.