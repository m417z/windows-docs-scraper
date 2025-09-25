# ICredentialProviderUserArray::GetAt

## Description

Retrieves a specified user from the array.

## Parameters

### `userIndex` [in]

The 0-based array index of the user. The size of the array can be obtained through the [GetCount](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruserarray-getcount) method.

### `user` [out]

The address of a pointer to an object that, when this method returns successfully, represents the specified user. It is the responsibility of the caller to free this object when it is no longer needed by calling its [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The index specified in *userIndex* is out of range. |

## See also

[ICredentialProviderUserArray](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruserarray)