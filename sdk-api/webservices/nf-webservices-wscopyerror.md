# WsCopyError function

## Description

Copies an error object from a specified source to a specified destination.

## Parameters

### `source` [in]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure representing the error object to copy.

### `destination` [in]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives the copied error object.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the error objects is **NULL**. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |