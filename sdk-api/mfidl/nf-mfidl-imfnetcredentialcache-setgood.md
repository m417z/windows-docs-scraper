# IMFNetCredentialCache::SetGood

## Description

Reports whether the credential object provided successfully passed the authentication challenge.

## Parameters

### `pCred` [in]

Pointer to the [IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential) interface.

### `fGood` [in]

**TRUE** if the credential object succeeded in the authentication challenge; otherwise, **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is called by the network source into the credential manager.

## See also

[IMFNetCredentialCache](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialcache)