# ICredentialProvider::UnAdvise

## Description

Used by the Logon UI or Credential UI to advise the credential provider that event callbacks are no longer accepted.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not need to be implemented, and should return **E_NOTIMPL** if it does not. There might be no reason to call it, such as if the Logon UI or Credential UI never changes or updates.

If this method is called, it indicates that the [ICredentialProviderEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialproviderevents) pointer provided in [Advise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-advise) is no longer valid. It is the responsibility of the credential provider to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the provided **ICredentialProviderEvents** pointer during this method.

**Important**

You should not use this method to clean up allocated memory for the credential provider. you should do that in the destructor of the credential provider as normal.

## See also

[ICredentialProvider](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovider)

[ICredentialProvider::Advise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-advise)