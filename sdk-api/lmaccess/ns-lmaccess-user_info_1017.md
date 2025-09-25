# USER_INFO_1017 structure

## Description

The
**USER_INFO_1017** structure contains expiration information for network user accounts. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1017_acct_expires`

Specifies a **DWORD** value that indicates when the user account expires. The user account is specified in the *username* parameter to the
**NetUserSetInfo** function.

The value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. Specify TIMEQ_FOREVER to indicate that the account never expires.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)