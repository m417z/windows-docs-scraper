# WsGetNamespaceFromPrefix function

## Description

This function returns a namespace from the prefix to which it is bound.

If the value of the *required* parameter is set to **TRUE** and the Prefix is not bound to any namespace a **WS_E_INVALID_FORMAT** exception will be returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) If the *required* parameter is **FALSE**, and the Prefix is not bound to any namespace the *ns* parameter will be **NULL** and the function will return S_FALSE.

## Parameters

### `reader` [in]

A pointer to the reader for which the prefix should be searched.

### `prefix` [in]

A pointer to the Prefix to search for.

### `required` [in]

The value of this Boolean parameter determines
whether or not an error should be returned if a matching namespace is not found.

### `ns`

A reference to a namespace to which the prefix is bound if successful. The value returned is valid only until the writer advances.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

For the prefix "xml" it will return the namespace "http://www.w3.org/XML/1998/namespace".

For the prefix "xmlns" it will return the namespace "http://www.w3.org/2000/xmlns/".