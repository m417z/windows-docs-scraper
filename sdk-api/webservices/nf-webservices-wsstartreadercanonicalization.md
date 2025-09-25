# WsStartReaderCanonicalization function

## Description

This operation begins the process of putting the specified XML Reader in a standard or "canonized" form.
The usage pattern for canonicalization is:

* Move the Reader to the element where canonicalization begins.
* Call **WsStartReaderCanonicalization**.
* Move the Reader forward to the end position.
* Call [WsEndReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendreadercanonicalization).

During this process the canonical bytes are written to the specified writeCallback.

**Note** Nodes advanced over
are canonicalized including nodes of child elements skipped using [WsSkipNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsskipnode). This is beneficial because it means that canonicalization and parsing can be done in one pass over the XML content regardless of what functions are used to read the data.

In order to use the XML Reader solely for canonicalizing an XML element node the application can call **WsStartReaderCanonicalization**, [WsSkipNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsskipnode) and [WsEndReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendreadercanonicalization) when the Reader is positioned on the element.
**WsEndReaderCanonicalization** must be called in order to ensure that all canonicalized bytes are written to the specified callback.

**Note** `WsEndReaderCanonicalization` must be called at the same depth at which **WsStartReaderCanonicalization**. Other reader functions return an error if moved to a depth lower than where **WsStartReaderCanonicalization** was called.
d

It is not valid to call [WsMoveReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovereader) or [WsSetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetreaderposition) on a Reader between calls to **WsStartReaderCanonicalization** and [WsEndReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendreadercanonicalization).

## Parameters

### `reader` [in]

A pointer to the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object on which canonicalization is started. The pointer must reference a valid **XML Reader** object.

### `writeCallback` [in]

A callback function invoked to write the canonical bytes as they are generated.

**Note** This callback is invoked synchronously.

### `writeCallbackState` [in]

A pointer to a caller-defined state that is passed when invoking the [WS_WRITE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_callback).

### `properties`

An "array" reference of optional properties controlling how canonicalization is performed.

**Note** See [WS_XML_CANONICALIZATION_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_canonicalization_property) for details.

### `propertyCount` [in]

The number of properties.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

Calls to this function cannot be nested. Consequently a call to **WsStartReaderCanonicalization** must be followed by a call to [WsEndReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsendreadercanonicalization) before the next **WsStartReaderCanonicalization** call can be made.

If a [WS_XML_CANONICALIZATION_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_canonicalization_algorithm) is not specified **WS_EXCLUSIVE_XML_CANONICALIZATION_ALGORITHM** is used.

The **WS_INCLUSIVE_XML_CANONICALIZATION_ALGORITHM** and
**WS_INCLUSIVE_WITH_COMMENTS_XML_CANONICALIZATION_ALGORITHM** algorithms can only be used with
entire XML documents. The Reader must be positioned at **WS_XML_NODE_TYPE_BOF** when
**WsStartReaderCanonicalization** is called with these algorithms.