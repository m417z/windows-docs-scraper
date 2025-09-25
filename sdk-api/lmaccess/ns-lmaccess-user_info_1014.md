# USER_INFO_1014 structure

## Description

The
**USER_INFO_1014** structure contains the names of workstations from which the user can log on. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1014_workstations`

> [!IMPORTANT]
> You should no longer use **usri1014_workstations**. Instead, you can control sign-in access to workstations by configuring the User Rights Assignment settings (**Allow log on locally** and **Deny log on locally**, or **Allow log on through Remote Desktop Services** and **Deny log on through Remote Desktop Services**).

Pointer to a Unicode string that contains the names of workstations from which the user can log on. The user is specified in the *username* parameter to the
**NetUserSetInfo** function.

As many as eight workstations can be specified; the names must be separated by commas. A null string indicates that there is no restriction.

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)