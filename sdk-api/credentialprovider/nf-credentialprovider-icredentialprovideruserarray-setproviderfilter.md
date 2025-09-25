# ICredentialProviderUserArray::SetProviderFilter

## Description

Limits the set of users in the array to either local accounts or Microsoft accounts.

## Parameters

### `guidProviderToFilterTo` [in]

Set this parameter to Identity_LocalUserProvider for the local accounts credential provider; otherwise set it to the GUID of the Microsoft account provider.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [ICredentialProviderUserArray](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario) object contains all of the available users in the current [scenario](https://learn.microsoft.com/windows/desktop/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario). This method enables your credential provider to specify a particular subset of those users. For example, if your credential provider handles only Microsoft account users from a specific connected provider, it can call this method with the Microsoft account provider's ID to filter out users that belong to other providers.

This method can only be called once, to filter for a single account provider. If the method is called again, the call will fail with a return value of E_UNEXPECTED.

## See also

[ICredentialProviderUser::GetProviderID](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getproviderid)

[ICredentialProviderUserArray](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruserarray)