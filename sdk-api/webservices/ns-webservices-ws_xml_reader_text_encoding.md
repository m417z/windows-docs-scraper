# WS_XML_READER_TEXT_ENCODING structure

## Description

Used to indicate that the reader should interpret the bytes it reads as textual xml.

## Members

### `encoding`

The base type for all types that derive from [WS_XML_READER_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_encoding).

### `charSet`

Indicates the text encoding of the bytes. If [WS_CHARSET_AUTO](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_charset) is specified then the reader will
determine the encoding of the document based on the first few bytes of the document. If an xml declaration
is present in the document, the reader will ensure that the encoding attribute coincides with this value.