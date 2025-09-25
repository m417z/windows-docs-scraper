# USER_INFO_1023 structure

## Description

The
**USER_INFO_1023** structure contains the name of the server to which network logon requests should be sent. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1023_logon_server`

Pointer to a Unicode string that contains the name of the server to which logon requests for the user account should be sent. The user account is specified in the *username* parameter to the
**NetUserSetInfo** function.

Server names should be preceded by two backslashes (\\). To indicate that the logon request can be handled by any logon server, specify an asterisk (\\*) for the server name. A null string indicates that requests should be sent to the domain controller.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)