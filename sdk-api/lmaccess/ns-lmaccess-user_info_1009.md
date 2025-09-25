# USER_INFO_1009 structure

## Description

The
**USER_INFO_1009** structure contains the path for a user's logon script file. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1009_script_path`

Pointer to a Unicode string specifying the path for the user's logon script file. The user is specified in the *username* parameter to the
**NetUserSetInfo** function. The script file can be a .CMD file, an .EXE file, or a .BAT file. The string can also be null.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)