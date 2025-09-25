# WsStartWriterCanonicalization function

## Description

Starts canonicalization on the specified XML writer.

## Parameters

### `writer` [in]

The XML writer on which canonicalization should be started.

### `writeCallback` [in]

The callback that to be invoked to write the canonical bytes as they are generated. This callback will always be invoked synchronously.

### `writeCallbackState` [in]

Caller-defined state that should be passed when invoking the [WS_WRITE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_callback).

### `properties`

An array of optional properties controlling how canonicalization is to be performed. See [WS_XML_CANONICALIZATION_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_canonicalization_property).

### `propertyCount` [in]

The number of properties.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

The usage pattern for canonicalization is to:

* call **WsStartWriterCanonicalization**,
* write the xml to be canonicalized,
* call [WsEndWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendwritercanonicalization).

During this process, the canonical bytes will be written to the specified writeCallback. Every node written by the writer will be canonicalized. Thus, canonicalization and generation can be done in one pass over regardless of what APIs are used to write the XML.
[WsEndWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendwritercanonicalization) must be called in order to ensure that all canonicalized bytes are written to the specified callback.

[WsEndWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendwritercanonicalization) must be called at the same depth at which **WsStartWriterCanonicalization** was called. Other writer APIs will return an error if it would move to a depth lower than where **WsStartWriterCanonicalization** was called.
It is an invalid operation to call [WsMoveWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovewriter) or [WsSetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetwriterposition) on a writer between a pair of matching **WsStartWriterCanonicalization** and [WsEndWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendwritercanonicalization) calls.

Calls to this API cannot be nested. So, a call to **WsStartWriterCanonicalization** must be followed by a call to [WsEndWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendwritercanonicalization) before the next **WsStartWriterCanonicalization** call.

If a [WS_XML_CANONICALIZATION_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_canonicalization_algorithm) is not specified, then **WS_EXCLUSIVE_XML_CANONICALIZATION_ALGORITHM** is used.

The [WS_INCLUSIVE_XML_CANONICALIZATION_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_canonicalization_algorithm) and **WS_INCLUSIVE_WITH_COMMENTS_XML_CANONICALIZATION_ALGORITHM** algorithms can only be used with entire xml documents. The writer must positioned at [WS_XML_NODE_TYPE_BOF](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_node_type) when **WsStartWriterCanonicalization** is called with these algorithms.