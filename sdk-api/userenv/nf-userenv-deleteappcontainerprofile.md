# DeleteAppContainerProfile function

## Description

Deletes the specified per-user, per-app profile.

**Note** Deleting a non-existent profile returns success.

## Parameters

### `pszAppContainerName` [in]

The name given to the profile in the call to the [CreateAppContainerProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createappcontainerprofile) function. This string is at most 64 characters in length, and fits into the pattern described by the regular expression "[-_. A-Za-z0-9]+".

## Return value

If this function succeeds, it returns a standard HRESULT code, including the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | If the method is called from within an app container. |
| **S_OK** | The profile was deleted successfully. |
| **E_INVALIDARG** | If the container name is **NULL**, or if it exceeds its specified limit for length. |

## Remarks

To ensure the best results, close all file handles in the profile storage locations before calling the **DeleteAppContainerProfile** function. Otherwise, this function may not be able to completely remove the storage locations for the profile.

This function deletes the profile for the current user. To delete the profile for another user, you must impersonate that user.

If the function fails, the status of the profile is undetermined, and you should call **DeleteAppContainerProfile** again to complete the operation.

## See also

[CreateAppContainerProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createappcontainerprofile)