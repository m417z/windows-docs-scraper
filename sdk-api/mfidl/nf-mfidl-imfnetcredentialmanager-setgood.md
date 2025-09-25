# IMFNetCredentialManager::SetGood

## Description

Specifies whether the user's credentials succeeded in the authentication challenge. The network source calls this method to informs the application whether the user's credentials were authenticated.

## Parameters

### `pCred` [in]

Pointer to the [IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential) interface.

### `fGood` [in]

Boolean value. The value is **TRUE** if the credentials succeeded in the authentication challenge. Otherwise, the value is **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetCredentialManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialmanager)