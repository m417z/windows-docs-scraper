# USER_INFO_1006 structure

## Description

The
**USER_INFO_1006** structure contains the user's home directory path. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1006_home_dir`

Pointer to a Unicode string specifying the path of the home directory for the user account specified in the *username* parameter to the
**NetUserSetInfo** function. The string can be null.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)