# USER_INFO_1024 structure

## Description

The
**USER_INFO_1024** structure contains the country/region code for a network user's language of choice. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1024_country_code`

Specifies a **DWORD** value that indicates the country/region code for the user's language of choice. The user is specified in the *username* parameter to the
**NetUserSetInfo** function.

This value is ignored.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)