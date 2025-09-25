# USER_INFO_1003 structure

## Description

The
**USER_INFO_1003** structure contains a user password. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1003_password`

Specifies a Unicode string that contains the password for the user account specified in the *username* parameter to the
**NetUserSetInfo** function. The length cannot exceed PWLEN bytes.

## Remarks

By convention, the length of passwords is limited to LM20_PWLEN characters.

## See also

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)