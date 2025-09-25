# USER_INFO_1025 structure

## Description

The
**USER_INFO_1025** structure contains the code page for a network user's language of choice. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1025_code_page`

Specifies a **DWORD** value that indicates the code page for the user's language of choice. The user is specified in the *username* parameter to the
**NetUserSetInfo** function.

This value is ignored.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)