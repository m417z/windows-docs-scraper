# CSecureChannelClient::GetAppSec

## Description

The **GetAppSec** method retrieves the application security levels of the local and remote components.

## Parameters

### `pdwLocalAppSec` [out]

Pointer to a **DWORD** specifying the application security level of the local component (the application).

### `pdwRemoteAppSec` [out]

Pointer to a **DWORD** specifying the application security level of the remote component (typically the service provider).

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| S_OK | The method succeeded. |
| E_INVALIDARG | A parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## See also

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)