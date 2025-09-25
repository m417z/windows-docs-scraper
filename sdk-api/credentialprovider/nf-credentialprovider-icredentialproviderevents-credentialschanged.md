# ICredentialProviderEvents::CredentialsChanged

## Description

Signals the Logon UI or Credential UI that the enumerated list of credentials has changed. This happens when the number of credentials change, the individual credentials change, or the number of fields available change. This is an asynchronous method.

## Parameters

### `upAdviseContext` [in]

Type: **UINT_PTR**

A pointer to an integer that uniquely identifies which credential provider has requested re-enumeration. The credential provider should pass back the interface pointer it received from [Advise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-advise) in this parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the past, many credential providers used **ICredentialProviderEvents::CredentialsChanged** to update UI. While this works, it causes a re-enumeration of all the credentials from the calling credential provider. The processing of this event can, under some circumstances, lead to flashing or focus changes in the UI due to this re-enumeration. Therefore, using **ICredentialProviderEvents::CredentialsChanged** solely for UI updates is discouraged. The new recommendation is as follows:

* Use **ICredentialProviderEvents::CredentialsChanged** only if a credential provider needs to do an auto logon or change the number of credentials it is enumerating.
* Use [ICredentialProviderCredentialEvents2](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents2) to update a credential provider's Logon UI or Credential UI.