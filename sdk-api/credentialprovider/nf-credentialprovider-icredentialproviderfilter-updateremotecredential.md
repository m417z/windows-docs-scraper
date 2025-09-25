# ICredentialProviderFilter::UpdateRemoteCredential

## Description

Updates a credential from a remote session.

## Parameters

### `pcpcsIn` [in]

Type: **const [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization)***

A constant pointer to a [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization) structure.

### `pcpcsOut` [out]

Type: **[CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization)***

A pointer to a [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.