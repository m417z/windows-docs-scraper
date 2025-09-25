# WS_XML_READER_BINARY_ENCODING structure

## Description

Used to indicate that the reader should interpret the bytes it reads as binary xml.

## Members

### `encoding`

The base type for all types that derive from [WS_XML_READER_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_encoding).

### `staticDictionary`

Indicates the dictionary that the reader should use for static strings. The binary representation of the xml
document references these strings by id (as opposed to embedding the actual string), and therefore they must contain
the same set of strings used when the document was written.

### `dynamicDictionary`

Indicates the dictionary that the reader should use for dynamic strings. These are strings that were not in the
staticDictionary when the document was written but that were found by the [WS_DYNAMIC_STRING_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_dynamic_string_callback).
The binary representation of the xml document references these strings by id (as opposed to embedding the actual string),
and therefore they must contain the same set of strings used when the document was written.
The application that uses the reader and writer must coordinate communicating the values referenced by these strings.