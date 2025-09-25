# ICredentialProviderCredential::Advise

## Description

Enables a credential to initiate events in the Logon UI or Credential UI through a callback interface. This method should be called before other methods in [ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential) interface.

## Parameters

### `pcpce` [in]

Type: **[ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents)***

A pointer to an [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) callback interface to be used as the notification mechanism.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is optional. If you do not implement this method, you should just return **E_NOTIMPL**.

Credential providers that implement this method have the responsibility of calling [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the provided [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents). Those credential providers also need to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) during the [UnAdvise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-unadvise) method.

## See also

[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)

[ICredentialProviderCredential::UnAdvise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-unadvise)