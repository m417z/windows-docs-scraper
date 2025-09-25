# IMFNetCredentialCache::SetUserOptions

## Description

Specifies how user credentials are stored.

## Parameters

### `pCred` [in]

Pointer to the [IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential) interface. Obtain this pointer by calling [IMFNetCredentialCache::GetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredentialcache-getcredential).

### `dwOptionsFlags` [in]

Bitwise **OR** of zero or more flags from the [MFNetCredentialOptions](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetcredentialoptions) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If no flags are specified, the credentials are cached in memory. This method can be implemented by the credential manager and called by the network source.

## See also

[IMFNetCredentialCache](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialcache)