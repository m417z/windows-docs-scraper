# WS_XML_STRING structure

## Description

Represents a string that optionally has [dictionary](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_dictionary)
information associated with it. The xml APIs use WS_XML_STRINGs to identify prefixes,
localNames and namespaces.

## Members

### `length`

The number of bytes in the UTF-8 encoded representation of the string.

### `bytes`

The string encoded as UTF-8 bytes.

### `dictionary`

A pointer to the dictionary that contains the string. If the string is not part of a dictionary
then the value may be **NULL**.

### `id`

A value that uniquely identifies the string within the specified dictionary.
The entry at dictionary->strings[id] should identify this string.

If the dictionary is **NULL**, then this value is unused.

## Remarks

The string is represented as UTF-8 encoded bytes, not WCHARs. It is not required to be zero terminated.

The macros [WS_XML_STRING_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-ws_xml_string_value), [WS_XML_STRING_NULL](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323562(v=vs.85)) and
[WS_XML_STRING_DICTIONARY_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-ws_xml_string_dictionary_value) can be used to initialize this structure.

The dictionary information is used by the binary encoding to write a more compact xml document.