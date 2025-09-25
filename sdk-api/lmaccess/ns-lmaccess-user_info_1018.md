# USER_INFO_1018 structure

## Description

The
**USER_INFO_1018** structure contains the maximum amount of disk space available to a network user account. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1018_max_storage`

Specifies a **DWORD** value that indicates the maximum amount of disk space the user can use. The user is specified in the *username* parameter to the
**NetUserSetInfo** function.

You must specify USER_MAXSTORAGE_UNLIMITED to indicate that there is no restriction on disk space.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)