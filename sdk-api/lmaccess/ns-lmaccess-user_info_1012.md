# USER_INFO_1012 structure

## Description

The
**USER_INFO_1012** structure contains a user comment. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1012_usr_comment`

Pointer to a Unicode string that contains a user comment. The user is specified in the *username* parameter to the
**NetUserSetInfo** function. This string can be a null string, or it can have any number of characters before the terminating null character.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)