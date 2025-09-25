# CheckDeveloperLicense function

## Description

Checks to see if a developer license exists.

## Parameters

### `pExpiration` [out]

Indicates when the developer license expires.

## Return value

Returns an [HResult structure](https://learn.microsoft.com/uwp/api/windows.foundation.hresult) with any error codes that occurred.

## Remarks

The following is a list of common error codes that this function returns:

| Error code | Description |
| --- | --- |
| S_OK | The function succeeded. |
| E_INVALIDARG | One or more arguments are invalid. |
| E_OUTOFMEMORY | Insufficient memory. |
| HRESULT_FROM_WIN32(ERROR_NOT_FOUND) | The license was not found. |
| HRESULT_FROM_WIN32(ERROR_NOT_AUTHENTICATED) | The call requires authentication. |
| HRESULT_FROM_WIN32(ERROR_NETWORK_UNREACHABLE) | The network can’t be reached. |
| HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED) | The caller doesn’t have access to the resource (license). |
| SEC_E_CONTEXT_EXPIRED | License is expired. |