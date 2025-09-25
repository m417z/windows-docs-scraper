# WS_XML_WRITER_RAW_ENCODING structure

## Description

Used to indicate that the writer should emit bytes from decoded base64 characters.

## Members

### `encoding`

The base type for all types that derive from [WS_XML_WRITER_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_encoding).

## Remarks

This encoding can be useful when it is desirable to write an arbitrary, perhaps, non-xml document
while still using the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) abstraction. In this encoding, only characters
representing base64 encoded bytes may be written, and only at the root of the document. No
elements or comments may be written. The writer will emit the bytes represented by the base64 encoded
characters. In order to accommodate non-whitespace text at the root of the document, the writer
will operate as if the [WS_XML_WRITER_PROPERTY_ALLOW_FRAGMENT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id) property has been specified.

The base64 characters of the document are only converted to bytes when necessary. So, for example,
using [WsWriteBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebytes), which normally performs a base64 encoding of the bytes it is passed,
actually avoids all base64 conversions and is the most efficient way to write documents in this
encoding. Using [WsWriteChars](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritechars), for example, will cause the base64 characters to physically get
decoded to their corresponding bytes. In general writing the document using anything other than
[WsReadBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbytes), [WsPullBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wspullbytes), or [WsPushBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wspushbytes) will incur the
base64 conversion.