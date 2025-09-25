# ICredentialProvider::GetCredentialCount

## Description

Gets the number of available credentials under this credential provider.

## Parameters

### `pdwCount` [out]

Type: **DWORD***

A pointer to a **DWORD** value that receives the count of credentials.

### `pdwDefault` [out]

Type: **DWORD***

A pointer to a **DWORD** value that receives the index of the credential to be used as the default. If no default value has been set, this value should be set to **CREDENTIAL_PROVIDER_NO_DEFAULT**.

### `pbAutoLogonWithDefault` [out]

Type: **BOOL***

A pointer to a **BOOL** value indicating if the default credential identified by *pdwDefault* should be used for an auto logon attempt. An auto logon attempt means the Logon UI or Credential UI will immediately call [GetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-getserialization) on the provider's default tile.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required.

When a Logon UI or Credential UI is ready for user interaction, a default credential is selected by default. Since each credential provider supplies a default credential, the following rules determine if *pdwDefault* will receive focus or if the credential will be automatically logged in.

* If a default credential has already been specified, that credential is not intended to be used for auto logon, and the *pdwDefault* is used for auto logon, then *pdwDefault* will be used as the default.
* If *pdwDefault* is from the last logged on provider and there isn't already a default with auto logon, then *pdwDefault* will be used as the default.
* If no default has been specified, then *pdwDefault* will be used as the default.

If the number of valid credentials change, the credential provider should call [CredentialsChanged](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialproviderevents-credentialschanged) on the [ICredentialProviderEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialproviderevents) instance provided in [Advise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-advise).

### Credential Provider Best Practices

Credential providers handle extremely sensitive user secrets in order to complete logon and unlock requests. As a best practice, secret information such as passwords and PINs should be handled with the utmost care. Proper techniques for handling secret information within a credential provider are:

* Always securely discard secrets. To do this, call [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) before freeing the memory used to hold any secret.
* Securely discard secrets promptly after they are used.
* Securely discard secrets if they are not used for their intended purpose within an expected amount of time.