# CSecureChannelClient::GetSessionKey

## Description

The **GetSessionKey** method retrieves the current session key. This method is not used by applications.

## Parameters

### `pbSPSessionKey` [out]

Pointer to the first byte of a buffer specifying the session key. The session key is used for encryption and decryption by the [EncryptParam](https://learn.microsoft.com/previous-versions/bb231587(v=vs.85)) and [DecryptParam](https://learn.microsoft.com/previous-versions/bb231586(v=vs.85)) methods.

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

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)

[CSecureChannelClient::SetSessionKey](https://learn.microsoft.com/previous-versions/ms868506(v=msdn.10))