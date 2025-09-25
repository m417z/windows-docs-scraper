# USER_INFO_1052 structure

## Description

The
**USER_INFO_1052** structure contains the path to a network user's profile. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1052_profile`

Specifies a Unicode string that contains the path to the user's profile. The user is specified in the *username* parameter to the
**NetUserSetInfo** function. This value can be a null string, a local absolute path, or a UNC path.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)