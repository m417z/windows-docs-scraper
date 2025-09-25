# ICredentialProviderUser::GetProviderID

## Description

Retrieves the ID of the account provider for this user.

## Parameters

### `providerID` [out]

A pointer to a value that, when this method returns successfully, receives the GUID of the user's account provider.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This GUID applies to both logon and credential UI.

This value can also be retrieved as a **PROPVARIANT** through [ICredentialProviderUser::GetValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getvalue).

## See also

[ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser)

[ICredentialProviderUser::GetValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getvalue)