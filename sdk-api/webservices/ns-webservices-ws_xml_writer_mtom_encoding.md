# WS_XML_WRITER_MTOM_ENCODING structure

## Description

Used to indicate that the reader should emit bytes in MTOM format.
The MTOM format will represent bytes written to it as binary mime
parts rather than embedded base64 encoded text.

## Members

### `encoding`

The base type for all types that derive from [WS_XML_WRITER_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_encoding).

### `textEncoding`

Specifies the encoding of the xml document carried by MTOM.

### `writeMimeHeader`

Specifies whether or not the writer should emit a MIME header.

### `boundary`

Specifies the character sequence that should be used to delimit the mime parts. This corresponds to the "boundary" parameter of the MIME Content-Type.

### `startInfo`

Specifies the type used by the mime part that contains the xml. This corresponds to the "start-info" parameter in the of the MIME Content-Type.

### `startUri`

Specifies the mime part that contains the xml. This corresponds to the "start" parameter of the MIME Content-Type.

### `maxInlineByteCount`

Specifies the threshold at which the writer will not write base64 encoded text and instead write a binary mime part for binary data.