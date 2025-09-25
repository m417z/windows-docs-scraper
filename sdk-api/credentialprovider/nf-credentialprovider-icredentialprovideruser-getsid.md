# ICredentialProviderUser::GetSid

## Description

Retrieves the user's security identifier (SID).

## Parameters

### `sid` [out]

The address of a pointer to a buffer that, when this method returns successfully, receives the user's SID. It is the responsibility of the caller to free this resource by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This SID applies to both logon and credential UI.

This value can also be retrieved as a **PROPVARIANT** through [ICredentialProviderUser::GetValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getvalue).

## See also

[ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser)

[ICredentialProviderUser::GetValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getvalue)