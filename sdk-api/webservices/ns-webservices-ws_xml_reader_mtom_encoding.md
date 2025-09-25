# WS_XML_READER_MTOM_ENCODING structure

## Description

Used to indicate that the reader should interpret the bytes it reads as in MTOM format.

## Members

### `encoding`

The base type for all types that derive from [WS_XML_READER_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_encoding).

### `textEncoding`

The encoding of the xml document carried by MTOM.

### `readMimeHeader`

Specifies whether or not the reader should read the MIME header.

### `startInfo`

The type used by the mime part that contains the xml. This corresponds to the "start-info" parameter in the of the MIME Content-Type.
If readMimeHeader is specified as **TRUE**, then this must be empty as the startInfo will be read from the mime header.

### `boundary`

The character sequence that should be used to delimit the mime parts. This corresponds to the "boundary" parameter of the MIME Content-Type.
If readMimeHeader is specified as **TRUE**, then this must be empty as the boundary will be read from the mime header.

### `startUri`

The mime part that contains the xml. This corresponds to the "start" parameter of the MIME Content-Type.
If readMimeHeader is specified as **TRUE**, then this must be empty as the startUri will be read from the mime header.

## Remarks

When used with [WS_XML_READER_BUFFER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_buffer_input) the MIME parts may appear in any order.

When used with [WS_XML_READER_STREAM_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_stream_input) the root MIME part must be first, and
subsequent MIME parts must appear in the order that they are referenced from xop:Include elements.

See http://www.w3.org/TR/2005/REC-xop10-20050125/ for the MTOM specification.