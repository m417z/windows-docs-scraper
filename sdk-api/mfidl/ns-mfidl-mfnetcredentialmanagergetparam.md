# MFNetCredentialManagerGetParam structure

## Description

Contains the authentication information for the credential manager.

## Members

### `hrOp`

The response code of the authentication challenge. For example, NS_E_PROXY_ACCESSDENIED.

### `fAllowLoggedOnUser`

Set this flag to **TRUE** if the currently logged on user's credentials should be used as the default credentials.

### `fClearTextPackage`

If **TRUE**, the authentication package will send unencrypted credentials over the network. Otherwise, the authentication package encrypts the credentials.

### `pszUrl`

The original URL that requires authentication.

### `pszSite`

The name of the site or proxy that requires authentication.

### `pszRealm`

The name of the realm for this authentication.

### `pszPackage`

The name of the authentication package. For example, "Digest" or "MBS_BASIC".

### `nRetries`

The number of times that the credential manager should retry after authentication fails.

## See also

[IMFNetCredentialManager::BeginGetCredentials](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredentialmanager-begingetcredentials)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Network Source Authentication](https://learn.microsoft.com/windows/desktop/medfound/network-source-authentication)