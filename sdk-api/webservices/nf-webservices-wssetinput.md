# WsSetInput function

## Description

Sets the encoding and input sources for an XML Reader.
These settings override settings made when the Reader was created.

**Note** If both encoding and input are **NULL** the reader will operate as if it is positioned at the end of an empty XML document.

## Parameters

### `reader` [in]

A pointer to the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object for which the input will be set.

### `encoding` [in, optional]

A to an encoding value that describes the format of the input bytes. This value should be one of:

* [WS_XML_READER_TEXT_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_text_encoding)
* [WS_XML_READER_BINARY_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_binary_encoding)
* [WS_XML_READER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_mtom_encoding)

### `input` [in, optional]

A pointer to a [WS_XML_READER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_input) structure that indicates the reader type.

### `properties`

An array reference of optional Reader properties.

### `propertyCount` [in]

The number of properties.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When **WsSetInput** is used on the XML Reader, the reader will function in a forward only manner and
the functions [WsGetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetreaderposition), [WsSetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetreaderposition) and [WsMoveReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovereader) cannot be used.