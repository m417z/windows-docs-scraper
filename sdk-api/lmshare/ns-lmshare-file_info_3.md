# FILE_INFO_3 structure

## Description

Contains the identification number and other pertinent information about files, devices, and pipes.

## Members

### `fi3_id`

Specifies a DWORD value that contains the identification number assigned to the resource when it is opened.

### `fi3_permissions`

Specifies a DWORD value that contains the access permissions associated with the opening application. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PERM_FILE_READ** | Permission to read a resource and, by default, execute the resource. |
| **PERM_FILE_WRITE** | Permission to write to a resource. |
| **PERM_FILE_CREATE** | Permission to create a resource; data can be written when creating the resource. |

### `fi3_num_locks`

Specifies a DWORD value that contains the number of file locks on the file, device, or pipe.

### `fi3_pathname`

Pointer to a string that specifies the path of the opened resource.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `fi3_username`

Pointer to a string that specifies which user (on servers that have user-level security) or which computer (on servers that have share-level security) opened the resource. Note that Windows does not support share-level security.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## See also

[FILE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_2)

[NetFile Functions](https://learn.microsoft.com/windows/desktop/NetShare/netfile-functions)

[NetFileEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netfileenum)

[NetFileGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netfilegetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)