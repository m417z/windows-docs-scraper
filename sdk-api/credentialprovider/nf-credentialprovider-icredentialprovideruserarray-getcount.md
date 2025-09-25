# ICredentialProviderUserArray::GetCount

## Description

Retrieves the number of [ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser) objects in the user array.

## Parameters

### `userCount` [out]

A pointer to a value that, when this method returns successfully, receives the number of users in the array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICredentialProviderUserArray](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruserarray)