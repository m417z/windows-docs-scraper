# WsReadXmlBufferFromBytes function

## Description

Uses a reader to convert a set of encoded bytes to a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

## Parameters

### `reader` [in]

The reader to use to parse the encoded bytes.

### `encoding` [in, optional]

The encoding to use when parsing the bytes. If **NULL**, a [WS_XML_READER_TEXT_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_reader_text_encoding)
with a charset of [WS_CHARSET_AUTO](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_charset) will be used.

### `properties`

An array of optional properties of the reader. See [WS_XML_READER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_property).

### `propertyCount` [in]

The number of properties.

### `bytes`

The bytes to parse.

### `byteCount` [in]

The number of bytes to parse.

### `heap` [in]

The heap from which to allocate the XML buffer.

### `xmlBuffer`

The XML buffer into which the bytes were read is returned here.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

The function will parse the entire contents according to the specified encoding and store it into a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

The reader will be left in an undefined state after calling this function. However, **WsReadXmlBufferFromBytes** may be used again with such a reader. Otherwise, [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput) or [WsSetInputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinputtobuffer) should be
used to bring the reader back to a known state, or the reader should be freed using [WsFreeReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreereader).