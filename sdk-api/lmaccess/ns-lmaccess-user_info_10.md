# USER_INFO_10 structure

## Description

The
**USER_INFO_10** structure contains information about a user account, including the account name, comments associated with the account, and the user's full name.

## Members

### `usri10_name`

Pointer to a Unicode string that specifies the name of the user account. Calls to the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function ignore this member. For more information, see the following Remarks section.

### `usri10_comment`

Pointer to a Unicode string that contains a comment associated with the user account. The string can be a null string, or can have any number of characters before the terminating null character.

### `usri10_usr_comment`

Pointer to a Unicode string that contains a user comment. This string can be a null string, or it can have any number of characters before the terminating null character.

### `usri10_full_name`

Pointer to a Unicode string that contains the full name of the user. This string can be a null string, or it can have any number of characters before the terminating null character.

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[NetUserDel](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserdel)

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)