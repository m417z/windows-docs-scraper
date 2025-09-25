# WsGetPrefixFromNamespace function

## Description

This function returns the prefix to which a namespace is bound.
There may be more than one prefix in scope and this function is free to return any one of them.

**Note** Under no
conditions should a caller depend upon or expect a particular prefix to be returned when there is
more than one prefix that may be returned.

If the value of the *required* parameter is set to **TRUE** and the Namespace is not bound to any Prefix a **WS_E_INVALID_FORMAT** exception will be returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) If the *required* parameter is **FALSE**, and the Namespace is not bound to any Prefix the *prefix* parameter is **NULL** and the function returns S_FALSE.

If [WsWriteStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartelement) is called but the element is not committed the Namespaces and Prefixes referenced by the element and any attributes on the element is not available to
this function.

## Parameters

### `writer` [in]

A pointer to a Writer with the namespace to search. This must be a valid **WS_XML_WRITER** object
returned by [WsCreateWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatewriter) and may not be **NULL**.

### `ns` [in]

The namespace to search for.

### `required` [in]

Indicates whether or not an error should be returned if a matching prefix is not found.

### `prefix`

A reference to a prefix bound to the namespace or **NULL** if the value of the *required* parameter is **FALSE** and a matching
namespace is not found.

**Note** The value returned is valid only until the writer advances.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

For the namespace "http://www.w3.org/XML/1998/namespace" it will return the prefix "xml".

For the namespace "http://www.w3.org/2000/xmlns/" it will return the prefix "xmlns".

The prefix returned should not be modified, and is only valid until the writer advances.