# ICredentialProvider::GetCredentialAt

## Description

Gets a specific credential.

## Parameters

### `dwIndex` [in]

Type: **DWORD**

The zero-based index of the credential within the set of credentials enumerated for this credential provider.

### `ppcpc` [out]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)****

The address of a pointer to a [ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential) instance representing the credential.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required.

The number of available credentials is retrieved by [ICredentialProvider::GetCredentialCount](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-getcredentialcount). This method is used by the Logon UI or Credential UI in conjunction with **GetCredentialCount** to enumerate the credentials.