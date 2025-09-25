# USER_INFO_22 structure

## Description

The
**USER_INFO_22** structure contains information about a user account, including the account name, privilege level, the path to the user's home directory, a one-way encrypted LAN Manager 2.*x*-compatible password, and other user-related network statistics.

## Members

### `usri22_name`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of the user account. Calls to the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function ignore this member. For more information, see the following Remarks section.

### `usri22_password`

Type: **BYTE[ENCRYPTED_PWLEN]**

A one-way encrypted LAN Manager 2.*x*-compatible password.

### `usri22_password_age`

Type: **DWORD**

The number of seconds that have elapsed since the **usri22_password** member was last changed. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri22_priv`

Type: **DWORD**

The level of privilege assigned to the **usri22_name** member. Calls to the
**NetUserAdd** function must specify USER_PRIV_USER. When you call the
**NetUserSetInfo** function this member must be the value returned from the
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) or the
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum) function. This member can be one of the following values. For more information about user and group account rights, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

| Value | Meaning |
| --- | --- |
| **USER_PRIV_GUEST** | Guest |
| **USER_PRIV_USER** | User |
| **USER_PRIV_ADMIN** | Administrator |

### `usri22_home_dir`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path of the home directory for the user specified by the **usri22_name** member. The string can be null.

### `usri22_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a comment associated with the user account. This string can be a null string, or it can have any number of characters before the terminating null character.

### `usri22_flags`

Type: **DWORD**

This member can be one or more of the following values.

Note that setting user account control flags may require certain [privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) and [control access rights](https://learn.microsoft.com/windows/desktop/AD/control-access-rights). For more information, see the Remarks section of the [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

| Value | Meaning |
| --- | --- |
| **UF_SCRIPT** | The logon script executed. This value must be set. |
| **UF_ACCOUNTDISABLE** | The user's account is disabled. |
| **UF_HOMEDIR_REQUIRED** | The home directory is required. This value is ignored. |
| **UF_PASSWD_NOTREQD** | No password is required. |
| **UF_PASSWD_CANT_CHANGE** | The user cannot change the password. |
| **UF_LOCKOUT** | The account is currently locked out. You can call the [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function to clear this value and unlock a previously locked account. You cannot use this value to lock a previously unlocked account. |
| **UF_DONT_EXPIRE_PASSWD** | The password should never expire on the account. |
| **UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED** | The user's password is stored under reversible encryption in the Active Directory. |
| **UF_NOT_DELEGATED** | Marks the account as "sensitive"; other users cannot act as delegates of this user account. |
| **UF_SMARTCARD_REQUIRED** | Requires the user to log on to the user account with a smart card. |
| **UF_USE_DES_KEY_ONLY** | Restrict this principal to use only Data Encryption Standard (DES) encryption types for keys. |
| **UF_DONT_REQUIRE_PREAUTH** | This account does not require Kerberos preauthentication for logon. |
| **UF_TRUSTED_FOR_DELEGATION** | The account is enabled for delegation. This is a security-sensitive setting; accounts with this option enabled should be tightly controlled. This setting allows a service running under the account to assume a client's identity and authenticate as that user to other remote servers on the network. |
| **UF_PASSWORD_EXPIRED** | The user's password has expired.<br><br>**Windows 2000:** This value is not supported. |
| **UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION** | The account is trusted to authenticate a user outside of the Kerberos security package and delegate that user through constrained delegation. This is a security-sensitive setting; accounts with this option enabled should be tightly controlled. This setting allows a service running under the account to assert a client's identity and authenticate as that user to specifically configured services on the network.<br><br>**Windows XP/2000:** This value is not supported. |

The following values describe the account type. Only one value can be set. You cannot change the account type using the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

| Value | Meaning |
| --- | --- |
| **UF_NORMAL_ACCOUNT** | This is a default account type that represents a typical user. |
| **UF_TEMP_DUPLICATE_ACCOUNT** | This is an account for users whose primary account is in another domain. This account provides user access to this domain, but not to any domain that trusts this domain. The User Manager refers to this account type as a local user account. |
| **UF_WORKSTATION_TRUST_ACCOUNT** | This is a computer account for a computer that is a member of this domain. |
| **UF_SERVER_TRUST_ACCOUNT** | This is a computer account for a backup domain controller that is a member of this domain. |
| **UF_INTERDOMAIN_TRUST_ACCOUNT** | This is a permit to trust account for a domain that trusts other domains. |

### `usri22_script_path`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path for the user's logon script file. The script file can be a .CMD file, an .EXE file, or a .BAT file. The string can also be null.

### `usri22_auth_flags`

Type: **DWORD**

The user's operator privileges.

Calls to the
**NetUserGetInfo** function and the
**NetUserEnum** function return a value based on the user's local group membership. If the user is a member of Print Operators, AF_OP_PRINT, is set. If the user is a member of Server Operators, AF_OP_SERVER, is set. If the user is a member of the Account Operators, AF_OP_ACCOUNTS, is set. AF_OP_COMM is never set.

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

### `usri22_full_name`

Type: **LPWSTR**

A pointer to a Unicode string that contains the full name of the user. This string can be a null string, or it can have any number of characters before the terminating null character.

### `usri22_usr_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a user comment. This string can be a null string, or it can have any number of characters before the terminating null character.

### `usri22_parms`

Type: **LPWSTR**

A pointer to a Unicode string that is reserved for use by applications. This string can be a null string, or it can have any number of characters before the terminating null character. Microsoft products use this member to store user configuration information. Do not modify this information.

### `usri22_workstations`

Type: **LPWSTR**

> [!IMPORTANT]
> You should no longer use **usri22_workstations**. Instead, you can control sign-in access to workstations by configuring the User Rights Assignment settings (**Allow log on locally** and **Deny log on locally**, or **Allow log on through Remote Desktop Services** and **Deny log on through Remote Desktop Services**).

A pointer to a Unicode string that contains the names of workstations from which the user can log on. As many as eight workstations can be specified; the names must be separated by commas. A null string indicates that there is no restriction. To disable logons from all workstations to this account, set the UF_ACCOUNTDISABLE value in the **usri22_flags** member.

### `usri22_last_logon`

Type: **DWORD**

The date and time when the last logon occurred. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. Calls to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The last logon occurred at the time indicated by the largest retrieved value.

### `usri22_last_logoff`

Type: **DWORD**

This member is currently not used.

The date and time when the last logoff occurred. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. A value of zero means that the last logoff time is unknown. This element is ignored by calls to
**NetUserAdd** and
**NetUserSetInfo**.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The last logoff occurred at the time indicated by the largest retrieved value.

### `usri22_acct_expires`

Type: **DWORD**

The date and time when the account expires. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. A value of TIMEQ_FOREVER indicates that the account never expires.

### `usri22_max_storage`

Type: **DWORD**

The maximum amount of disk space the user can use. Specify USER_MAXSTORAGE_UNLIMITED to use all available disk space.

### `usri22_units_per_week`

Type: **DWORD**

The number of equal-length time units into which the week is divided. This value is required to compute the length of the bit string in the **usri22_logon_hours** member.

This value must be UNITS_PER_WEEK for LAN Manager 2.0. Calls to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

For service applications, the units must be one of the following: SAM_DAYS_PER_WEEK, SAM_HOURS_PER_WEEK, or SAM_MINUTES_PER_WEEK.

### `usri22_logon_hours`

Type: **PBYTE**

A pointer to a 21-byte (168 bits) bit string that specifies the times during which the user can log on. Each bit represents a unique hour in the week, in Greenwich Mean Time (GMT).

The first bit (bit 0, word 0) is Sunday, 0:00 to 0:59; the second bit (bit 1, word 0) is Sunday, 1:00 to 1:59; and so on. Note that bit 0 in word 0 represents Sunday from 0:00 to 0:59 only if you are in the GMT time zone. In all other cases you must adjust the bits according to your time zone offset (for example, GMT minus 8 hours for Pacific Standard Time).

Specify a null pointer in this member when calling the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) function to indicate no time restriction. Specify a null pointer when calling the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function to indicate that no change is to be made to the times during which the user can log on.

### `usri22_bad_pw_count`

Type: **DWORD**

The number of times the user tried to log on to this account using an incorrect password. A value of – 1 indicates that the value is unknown. Calls to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

This member is replicated from the primary domain controller (PDC); it is also maintained on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The number of times the user tried to log on using an incorrect password is the largest value retrieved.

### `usri22_num_logons`

Type: **DWORD**

The number of times the user logged on successfully to this account. A value of – 1 indicates that the value is unknown. Calls to the
**NetUserAdd** and
**NetUserSetInfo** functions ignore this member.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The number of times the user logged on successfully is the sum of the retrieved values.

### `usri22_logon_server`

Type: **LPWSTR**

A pointer to a Unicode string that contains the name of the server to which logon requests are sent. Server names should be preceded by two backslashes (\\). To indicate that the logon request can be handled by any logon server, specify an asterisk (\\*) for the server name. A null string indicates that requests should be sent to the domain controller.

For Windows servers, the
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) and
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum) functions return \\*. Calls to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri22_country_code`

Type: **DWORD**

The country/region code for the user's language of choice.

This value is ignored.

### `usri22_code_page`

Type: **DWORD**

The code page for the user's language of choice.

This value is ignored.

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd)

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)