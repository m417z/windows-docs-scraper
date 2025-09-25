# ICredentialProviderUserArray::GetAccountOptions

## Description

Retrieves a value that indicates whether the "Other user" tile for local or Microsoft accounts is shown in the logon or credential UI. This information can be used by a credential provider to show the same behavior as the password or Microsoft account provider.

## Parameters

### `credentialProviderAccountOptions` [out]

A pointer to a value that, when this method returns successfully, receives one or more flags that specify which empty tiles are shown by the logon or credential UI.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICredentialProviderUserArray](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruserarray)