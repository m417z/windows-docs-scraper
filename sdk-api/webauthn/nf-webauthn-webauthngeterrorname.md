## Description

Gets the error name for the specified error code.

## Parameters

### `hr`

The **HRESULT** to get the error name for.

## Return value

An error name string.

## Remarks

Returns the following error codes:

| Error Code | Error Name |
|------------|------------|
| **S_OK** | Success |
| **NTE_EXISTS** | InvalidStateError |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)**<br>**NTE_NOT_SUPPORTED**<br>**NTE_TOKEN_KEYSET_STORAGE_FULL** | ConstraintError |
| **NTE_INVALID_PARAMETER** | NotSupporedError |
| **NTE_DEVICE_NOT_FOUND**<br>**NTE_NOT_FOUND**<br>**HRESULT_FROM_WIN32(ERROR_CANCELLED)**<br>**NTE_USER_CANCELLED**<br>**HRESULT_FROM_WIN32(ERROR_TIMEOUT)** | NotAllowedError |
| All other **HRESULT** values | UnknownError |

## See also

[WebAuthNGetW3CExceptionDOMError](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetw3cexceptiondomerror)