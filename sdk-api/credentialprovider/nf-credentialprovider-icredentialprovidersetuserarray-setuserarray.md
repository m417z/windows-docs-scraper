# ICredentialProviderSetUserArray::SetUserArray

## Description

Called by the system during the initialization of a logon or credential UI to retrieve the set of users to show in that UI.

## Parameters

### `users` [in]

A pointer to an array object that contains a set of [ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser) objects, each representing a user that will appear in the logon or credential UI. This array enables the credential provider to enumerate and query each of the user objects for their SID, their associated credential provider's ID, various forms of the user name, and their logon status string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Note that this method does not transfer ownership of the [ICredentialProviderUserArray](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruserarray) from the credential provider framework. The information it provides is cannot be altered.

## See also

[ICredentialProviderSetUserArray](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidersetuserarray)

[ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser)