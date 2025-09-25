# WS_XML_READER_RAW_ENCODING structure

## Description

Used to indicate that the reader should surface the bytes of the document as base64 encoded characters.

## Members

### `encoding`

The base type for all types that derive from [WS_XML_READER_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_encoding).

## Remarks

This encoding can be useful when it is desirable to read an arbitrary, perhaps, non-xml document
while still using the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) abstraction. In this encoding, the bytes comprising
the document are presented as base64 encoded characters at the root of a xml document. In order to
accommodate non-whitespace text at the root of the document, the reader will operate as if the
[WS_XML_READER_PROPERTY_ALLOW_FRAGMENT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id) property has been specified.

The bytes of the document are only converted to base64 when necessary. So, for example, using
[WsReadBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbytes), which normally performs a base64 decoding of the characters it reads,
actually avoids all base64 conversions and is the most efficient way to read documents in this
encoding. Using [WsReadChars](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadchars), for example, will cause the bytes to physically get
converted to their corresponding base64 characters. In general reading the document using
anything other than **WsReadBytes** will incur the base64 conversion.