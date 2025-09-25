# IMFNetCredentialCache::GetCredential

## Description

Retrieves the credential object for the specified URL.

## Parameters

### `pszUrl` [in]

A null-terminated wide-character string containing the URL for which the credential is needed.

### `pszRealm` [in]

A null-terminated wide-character string containing the realm for the authentication.

### `dwAuthenticationFlags` [in]

Bitwise **OR** of zero or more flags from the [MFNetAuthenticationFlags](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetauthenticationflags) enumeration.

### `ppCred` [out]

Receives a pointer to the [IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential) interface. The caller must release the interface.

### `pdwRequirementsFlags` [out]

Receives a bitwise **OR** of zero or more flags from the [MFNetCredentialRequirements](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetcredentialrequirements) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetCredentialCache](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialcache)