# WsWriteQualifiedName function

## Description

Writes an XML qualified name to the Writer.

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the qualified name is written. The pointer must reference a valid **XML Writer** object.

### `prefix` [in, optional]

A WS_XML_STRING pointer to the prefix used by the qualified name. If the value referenced by this parameter is **NULL** the Writer will choose a prefix.

### `localName` [in]

A WS_XML_STRING pointer to the local name used by the qualified name. It must be at least one character long.

### `ns` [in, optional]

A WS_XML_STRING pointer to the namespace used for the qualified name.
If no prefix is specified the Writer may use a prefix in scope that is bound to the specified namespace or it may generate a prefix and include an XMLNS attribute.

If a prefix is specified the Writer uses that prefix and may include an XMLNS attribute if needed to override an existing prefix in scope.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

* If the prefix is **NULL**, then the namespace must not be **NULL**. In this case the writer will try to find a prefix in scope that is bound to the specified namespace. If an appropriate prefix is found it will be used. If not the Writer will generate a prefix and insert an XMLNS attribute on the current element. If the writer is not in an element, then the function will return **WS_E_INVALID_FORMAT**.

  (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)
* If the prefix is not **NULL** and the namespace is not **NULL** the Writer will verify that the prefix is currently bound to the specified namespace and will return **WS_E_INVALID_FORMAT** if not.
* If the prefix is not **NULL** and the namespace is **NULL** the Writer will use the prefix and local name to write the qualified name.