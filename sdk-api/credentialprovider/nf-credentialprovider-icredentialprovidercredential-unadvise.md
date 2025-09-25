# ICredentialProviderCredential::UnAdvise

## Description

Used by the Logon UI or Credential UI to advise the credential that event callbacks are no longer accepted.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is optional. If you do not implement this method, you should just return **E_NOTIMPL**.

If this method is called, it indicates that the [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) pointer provided in [Advise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-advise) is no longer valid. It is the responsibility of the credential provider to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the provided **ICredentialProviderCredentialEvents** pointer during this method.

## See also

[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)

[ICredentialProviderCredential::Advise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-advise)