# CSecureChannelServer::SetSessionKey

## Description

The **SetSessionKey** method sets the session key that is used to communicate with another component. This method is published and available, but normally is used only by Windows Media Device Manager.

## Parameters

### `pbSPSessionKey` [in]

Pointer to the first byte of the session key that is to be set. The key is used for encryption and decryption.

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
| E_INVALIDARG | The pbSPSessionKey parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[CSecureChannelServer::GetSessionKey](https://learn.microsoft.com/previous-versions/bb231602(v=vs.85))