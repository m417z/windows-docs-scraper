# WS_XML_CANONICALIZATION_PROPERTY_ID enumeration

## Description

Identifies each XML canonicalization property and its associated
value. This enumeration is used within the [WS_XML_CANONICALIZATION_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_canonicalization_property) structure, which is used as a parameter to [WsStartReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartreadercanonicalization) and [WsStartWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartwritercanonicalization).

## Constants

### `WS_XML_CANONICALIZATION_PROPERTY_ALGORITHM:0`

A [WS_XML_CANONICALIZATION_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_canonicalization_algorithm) value that specifies the algorithm to be used for canonicalization. If this is not specified,
the **WS_EXCLUSIVE_XML_CANONICALIZATION_ALGORITHM** is used.

### `WS_XML_CANONICALIZATION_PROPERTY_INCLUSIVE_PREFIXES:1`

A [WS_XML_CANONICALIZATION_INCLUSIVE_PREFIXES](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_canonicalization_inclusive_prefixes) structure that contains the set of prefixes to be treated as inclusive prefixes when using
the exclusive canonicalization algorithm. If this is not specified,
no prefix is treated as an inclusive prefix.

### `WS_XML_CANONICALIZATION_PROPERTY_OMITTED_ELEMENT:2`

A [WS_XML_QNAME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_qname) structure that contains the elements to be omitted during canonicalization. If one or more
elements in the XML input match the specified name and namespace, then
all such elements and the subtrees rooted at them are omitted from the
canonical output. This property can be used to implement enveloped
signatures where canonicalization needs to skip a signature element
that is embedded within the XML content being canonicalized and
signed. If this is not specified, no element is omitted from the
output.

### `WS_XML_CANONICALIZATION_PROPERTY_OUTPUT_BUFFER_SIZE:3`

A **ULONG** that specifies the size of the buffer in which canonical bytes are accumulated. Once at least this
many bytes are generated, or canonicalization is ended by a call to [WsEndReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendreadercanonicalization) or [WsEndWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendwritercanonicalization), the canonical bytes are
written to the output specified at the start of canonicalization. If this is
not specified, a default buffer size of 1024 is used.