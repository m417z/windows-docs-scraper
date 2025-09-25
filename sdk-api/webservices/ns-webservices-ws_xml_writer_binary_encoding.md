# WS_XML_WRITER_BINARY_ENCODING structure

## Description

Used to indicate that the writer should emit bytes as binary xml.

## Members

### `encoding`

The base type for all types that derive from [WS_XML_WRITER_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_encoding).

### `staticDictionary`

Indicates the dictionary that the writer should use for static strings. [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string)s that are written that
reference this dictionary, will be written in the binary xml document using an id rather than the string itself.
When reading this document, the application must provide a dictionary with the same strings.

### `dynamicStringCallback`

Specifies an optional callback that the writer will invoke when a [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) that is not found in the staticDictionary is written for the first time.
The callback provides the mapping to an id which the writer will then use. It is the responsibility of the callback to coordinate with the
writer to propagate these strings to the reader. The string is not added to the dictionary if this callback is not specified.

### `dynamicStringCallbackState`

User-defined state that will be passed to dynamicStringCallback.