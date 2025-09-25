# USER_INFO_1007 structure

## Description

The
**USER_INFO_1007** structure contains a comment associated with a user network account. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1007_comment`

Pointer to a Unicode string that contains a comment to associate with the user account specified in the *username* parameter to the
**NetUserSetInfo** function. This string can be a null string, or it can have any number of characters before the terminating null character.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)