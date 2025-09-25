# IBackgroundCopyJob3::GetFileACLFlags

## Description

Retrieves the flags that identify the owner and ACL information to maintain when transferring a file using SMB.

## Parameters

### `Flags` [out]

Flags that identify the owner and ACL information to maintain when transferring a file using SMB. *Flags* can contain any combination of the following flags. If no flags are set, *Flags* is zero.

| Value | Meaning |
| --- | --- |
| **BG_COPY_FILE_OWNER** | If set, the file's owner information is maintained. Otherwise, the job's owner becomes the owner of the file. |
| **BG_COPY_FILE_GROUP** | If set, the file's group information is maintained. Otherwise, BITS uses the job owner's primary group to assign the group information to the file. |
| **BG_COPY_FILE_DACL** | If set, BITS copies the explicit ACEs from the source file and inheritable ACEs from the destination parent folder. Otherwise, BITS copies the inheritable ACEs from the destination parent folder. If the parent folder does not contain inheritable ACEs, BITS uses the default DACL from the account. |
| **BG_COPY_FILE_SACL** | If set, BITS copies the explicit ACEs from the source file and inheritable ACEs from the destination parent folder. Otherwise, BITS copies the inheritable ACEs from the destination parent folder. |
| **BG_COPY_FILE_ALL** | If set, BITS copies the owner and ACL information. This is the same as setting all the flags individually. |

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the flags. |

## See also

[IBackgroundCopyJob3](https://learn.microsoft.com/windows/desktop/api/bits2_0/nn-bits2_0-ibackgroundcopyjob3)

[IBackgroundCopyJob3::SetFileACLFlags](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-setfileaclflags)