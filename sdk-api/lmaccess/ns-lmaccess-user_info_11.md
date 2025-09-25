# USER_INFO_11 structure

## Description

The
**USER_INFO_11** structure contains information about a user account, including the account name, privilege level, the path to the user's home directory, and other user-related network statistics.

## Members

### `usri11_name`

Type: **LPWSTR**

A pointer to a Unicode character that specifies the name of the user account. Calls to the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function ignore this member. For more information, see the following Remarks section.

### `usri11_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a comment associated with the user account. This string can be a **NULL** string, or it can have any number of characters before the terminating null character.

### `usri11_usr_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a user comment. This string can be a **NULL** string, or it can have any number of characters before the terminating null character.

### `usri11_full_name`

Type: **LPWSTR**

A pointer to a Unicode string that contains the full name of the user. This string can be a **NULL** string, or it can have any number of characters before the terminating null character.

### `usri11_priv`

Type: **DWORD**

The level of privilege assigned to the **usri11_name** member. For calls to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) function, this member must be USER_PRIV_USER. For calls to
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo), this member must be the value returned from the
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function or the
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum) function. This member can be one of the following values. For more information about user and group account rights, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

| Value | Meaning |
| --- | --- |
| **USER_PRIV_GUEST** | Guest |
| **USER_PRIV_USER** | User |
| **USER_PRIV_ADMIN** | Administrator |

### `usri11_auth_flags`

Type: **DWORD**

A set of bit flags defining the user's operator privileges.

Calls to the
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function and the
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum) function return a value based on the user's local group membership. If the user is a member of Print Operators, AF_OP_PRINT is set. If the user is a member of Server Operators, AF_OP_SERVER is set. If the user is a member of the Account Operators, AF_OP_ACCOUNTS is set. AF_OP_COMM is never set.

The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

The following restrictions apply:

* When you call the
  [NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) function, this member must be zero.
* When you call the
  [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function, this member must be the value returned from a call to
  [NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) or to
  [NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum).

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **AF_OP_PRINT** | The print operator privilege is enabled. |
| **AF_OP_COMM** | The communications operator privilege is enabled. |
| **AF_OP_SERVER** | The server operator privilege is enabled. |
| **AF_OP_ACCOUNTS** | The accounts operator privilege is enabled. |

### `usri11_password_age`

Type: **DWORD**

The number of seconds that have elapsed since the **usri11_password** member was last changed. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri11_home_dir`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path of the home directory for the user specified in the **usri11_name** member. The string can be **NULL**.

### `usri11_parms`

Type: **LPWSTR**

A pointer to a Unicode string that is reserved for use by applications. This string can be a **NULL** string, or it can have any number of characters before the terminating null character. Microsoft products use this member to store user configuration information. Do not modify this information.

### `usri11_last_logon`

Type: **DWORD**

The date and time when the last logon occurred. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The last logon occurred at the time indicated by the largest retrieved value.

### `usri11_last_logoff`

Type: **DWORD**

This member is currently not used.

The date and time when the last logoff occurred. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. A value of zero indicates that the last logoff time is unknown. The
**NetUserAdd** function and the
**NetUserSetInfo** function ignore this member.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The last logoff occurred at the time indicated by the largest retrieved value.

### `usri11_bad_pw_count`

Type: **DWORD**

The number of times the user tried to log on to this account using an incorrect password. A value of – 1 indicates that the value is unknown. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

This member is replicated from the primary domain controller (PDC); it is also maintained on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The number of times the user tried to log on using an incorrect password is the largest value retrieved.

### `usri11_num_logons`

Type: **DWORD**

The number of times the user has logged on successfully to this account. A value of – 1 indicates that the value is unknown. Calls to the
**NetUserAdd** and
**NetUserSetInfo** functions ignore this member.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The number of times the user logged on successfully is the sum of the retrieved values.

### `usri11_logon_server`

Type: **LPWSTR**

A pointer to a Unicode string that contains the name of the server to which logon requests are sent. Server names should be preceded by two backslashes (\\). To indicate that the logon request can be handled by any logon server, specify an asterisk (\\*) for the server name. A **NULL** string indicates that requests should be sent to the domain controller.

For Windows servers,
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) and
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum) return \\*. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri11_country_code`

Type: **DWORD**

The country/region code for the user's language of choice.

### `usri11_workstations`

Type: **LPWSTR**

A pointer to a Unicode string that contains the names of workstations from which the user can log on. As many as eight workstations can be specified; the names must be separated by commas. A **NULL** string indicates that there is no restriction. To disable logons from all workstations to this account, set the UF_ACCOUNTDISABLE value in the **usri11_flags** member.

### `usri11_max_storage`

Type: **DWORD**

The maximum amount of disk space the user can use. Specify USER_MAXSTORAGE_UNLIMITED to use all available disk space.

### `usri11_units_per_week`

Type: **DWORD**

The number of equal-length time units into which the week is divided. This value is required to compute the length of the bit string in the **usri11_logon_hours** member.

This member must be UNITS_PER_WEEK for LAN Manager 2.0. This element is ignored by the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions.

For service applications, the units must be one of the following values: SAM_DAYS_PER_WEEK, SAM_HOURS_PER_WEEK, or SAM_MINUTES_PER_WEEK.

### `usri11_logon_hours`

Type: **PBYTE**

A pointer to a 21-byte (168 bits) bit string that specifies the times during which the user can log on. Each bit represents a unique hour in the week, in Greenwich Mean Time (GMT).

The first bit (bit 0, word 0) is Sunday, 0:00 to 0:59; the second bit (bit 1, word 0) is Sunday, 1:00 to 1:59; and so on. Note that bit 0 in word 0 represents Sunday from 0:00 to 0:59 only if you are in the GMT time zone. In all other cases you must adjust the bits according to your time zone offset (for example, GMT minus 8 hours for Pacific Standard Time).

Specify a **NULL** pointer in this member when calling the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) function to indicate no time restriction. Specify a **NULL** pointer when calling the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function to indicate that no change is to be made to the times during which the user can log on.

### `usri11_code_page`

Type: **DWORD**

The code page for the user's language of choice.

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd)

[NetUserDel](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserdel)

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)