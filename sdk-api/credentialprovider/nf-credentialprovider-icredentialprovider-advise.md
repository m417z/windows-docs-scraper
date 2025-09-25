# ICredentialProvider::Advise

## Description

Allows a credential provider to initiate events in the Logon UI or Credential UI through a callback interface.

## Parameters

### `pcpe` [in]

Type: **[ICredentialProviderEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialproviderevents)***

A pointer to an [ICredentialProviderEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialproviderevents) callback interface to be used as the notification mechanism.

### `upAdviseContext` [in]

Type: **UINT_PTR**

A pointer to an integer that uniquely identifies which credential provider has requested re-enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The method does not need to be implemented, and should return **E_NOTIMPL** if it doesn't. There might be no reason to call it, such as if the Logon UI or Credential UI never changes or updates.

This method enables the Logon UI and the Credential UI to pass an [ICredentialProviderEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialproviderevents) pointer to the credential provider. This enables the credential provider to have asynchronous callback communication with the Logon or Credential UI. For example, a smart card provider might want to enumerate credentials again when a new smart card is inserted. In order to trigger the Logon UI to get credentials again, the credential provider should call [CredentialsChanged](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialproviderevents-credentialschanged) providing the *upAdviseContext* identifier.

Credential providers that implement this method have the responsibility of calling [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the provided [ICredentialProviderEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialproviderevents). Those credential providers also need to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) during the [UnAdvise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-unadvise) method.

## See also

[ICredentialProvider](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovider)

[ICredentialProvider::UnAdvise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-unadvise)