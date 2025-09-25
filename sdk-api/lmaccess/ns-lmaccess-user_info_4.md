# USER_INFO_4 structure

## Description

The
**USER_INFO_4** structure contains information about a user account, including the account name, password data, privilege level, the path to the user's home directory, security identifier (SID), and other user-related network statistics.

## Members

### `usri4_name`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of the user account. For the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function, this member is ignored.

### `usri4_password`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the password for the user identified by the **usri4_name** member. The length cannot exceed PWLEN bytes. The
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function returns a **NULL** pointer to maintain password security.

By convention, the length of passwords is limited to LM20_PWLEN characters.

### `usri4_password_age`

Type: **DWORD**

The number of seconds that have elapsed since the **usri4_password** member was last changed. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri4_priv`

Type: **DWORD**

The level of privilege assigned to the **usri4_name** member. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member. This member can be one of the following values. For more information about user and group account rights, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

| Value | Meaning |
| --- | --- |
| **USER_PRIV_GUEST** | Guest |
| **USER_PRIV_USER** | User |
| **USER_PRIV_ADMIN** | Administrator |

### `usri4_home_dir`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path of the home directory of the user specified by the **usri4_name** member. The string can be **NULL**.

### `usri4_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a comment to associate with the user account. The string can be a **NULL** string, or it can have any number of characters before the terminating null character.

### `usri4_flags`

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
| **UF_PASSWORD_EXPIRED** | The user's password has expired.<br><br>**Windows 2000:** This value is ignored. |
| **UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION** | The account is trusted to authenticate a user outside of the Kerberos security package and delegate that user through constrained delegation. This is a security-sensitive setting; accounts with this option enabled should be tightly controlled. This setting allows a service running under the account to assert a client's identity and authenticate as that user to specifically configured services on the network.<br><br>**Windows XP/2000:** This value is ignored. |

The following values describe the account type. Only one value can be set. You cannot change the account type using the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

| Value | Meaning |
| --- | --- |
| **UF_NORMAL_ACCOUNT** | This is a default account type that represents a typical user. |
| **UF_TEMP_DUPLICATE_ACCOUNT** | This is an account for users whose primary account is in another domain. This account provides user access to this domain, but not to any domain that trusts this domain. The User Manager refers to this account type as a local user account. |
| **UF_WORKSTATION_TRUST_ACCOUNT** | This is a computer account for a computer that is a member of this domain. |
| **UF_SERVER_TRUST_ACCOUNT** | This is a computer account for a backup domain controller that is a member of this domain. |
| **UF_INTERDOMAIN_TRUST_ACCOUNT** | This is a permit to trust account for a domain that trusts other domains. |

### `usri4_script_path`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path for the user's logon script file. The script file can be a .CMD file, an .EXE file, or a .BAT file. The string can also be **NULL**.

### `usri4_auth_flags`

Type: **DWORD**

The user's operator privileges.

For the
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function, the appropriate value is returned based on the local group membership. If the user is a member of Print Operators, AF_OP_PRINT is set. If the user is a member of Server Operators, AF_OP_SERVER is set. If the user is a member of the Account Operators, AF_OP_ACCOUNTS is set. AF_OP_COMM is never set.

The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **AF_OP_PRINT** | The print operator privilege is enabled. |
| **AF_OP_COMM** | The communications operator privilege is enabled. |
| **AF_OP_SERVER** | The server operator privilege is enabled. |
| **AF_OP_ACCOUNTS** | The accounts operator privilege is enabled. |

### `usri4_full_name`

Type: **LPWSTR**

A pointer to a Unicode string that contains the full name of the user. This string can be a **NULL** string, or it can have any number of characters before the terminating null character.

### `usri4_usr_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a user comment. This string can be a **NULL** string, or it can have any number of characters before the terminating null character.

### `usri4_parms`

Type: **LPWSTR**

A pointer to a Unicode string that is reserved for use by applications. This string can be a **NULL** string, or it can have any number of characters before the terminating null character. Microsoft products use this member to store user configuration information. Do not modify this information.

### `usri4_workstations`

Type: **LPWSTR**

> [!IMPORTANT]
> You should no longer use **usri4_workstations**. Instead, you can control sign-in access to workstations by configuring the User Rights Assignment settings (**Allow log on locally** and **Deny log on locally**, or **Allow log on through Remote Desktop Services** and **Deny log on through Remote Desktop Services**).

A pointer to a Unicode string that contains the names of workstations from which the user can log on. As many as eight workstations can be specified; the names must be separated by commas. If you do not want to restrict the number of workstations, use a **NULL** string. To disable logons from all workstations to this account, set the UF_ACCOUNTDISABLE value in the **usri4_flags** member.

### `usri4_last_logon`

Type: **DWORD**

The date and time when the last logon occurred. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. This member is ignored by the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The last logon occurred at the time indicated by the largest retrieved value.

### `usri4_last_logoff`

Type: **DWORD**

This member is currently not used.

The date and time when the last logoff occurred. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. A value of zero indicates that the last logoff time is unknown.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The last logoff occurred at the time indicated by the largest retrieved value.

### `usri4_acct_expires`

Type: **DWORD**

The date and time when the account expires. This value is stored as the number of seconds elapsed since 00:00:00, January 1, 1970, GMT. A value of TIMEQ_FOREVER indicates that the account never expires.

### `usri4_max_storage`

Type: **DWORD**

The maximum amount of disk space the user can use. Specify USER_MAXSTORAGE_UNLIMITED to use all available disk space.

### `usri4_units_per_week`

Type: **DWORD**

The number of equal-length time units into which the week is divided. This value is required to compute the length of the bit string in the **usri4_logon_hours** member.

This value must be UNITS_PER_WEEK for LAN Manager 2.0. This element is ignored by the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions.

For service applications, the units must be one of the following values: SAM_DAYS_PER_WEEK, SAM_HOURS_PER_WEEK, or SAM_MINUTES_PER_WEEK.

### `usri4_logon_hours`

Type: **PBYTE**

A pointer to a 21-byte (168 bits) bit string that specifies the times during which the user can log on. Each bit represents a unique hour in the week, in Greenwich Mean Time (GMT).

The first bit (bit 0, word 0) is Sunday, 0:00 to 0:59; the second bit (bit 1, word 0) is Sunday, 1:00 to 1:59; and so on. Note that bit 0 in word 0 represents Sunday from 0:00 to 0:59 only if you are in the GMT time zone. In all other cases you must adjust the bits according to your time zone offset (for example, GMT minus 8 hours for Pacific Standard Time).

Specify a **NULL** pointer in this member when calling the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) function to indicate no time restriction. Specify a **NULL** pointer when calling the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function to indicate that no change is to be made to the times during which the user can log on.

### `usri4_bad_pw_count`

Type: **DWORD**

The number of times the user tried to log on to the account using an incorrect password. A value of – 1 indicates that the value is unknown. Calls to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

This member is replicated from the primary domain controller (PDC); it is also maintained on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The number of times the user tried to log on using an incorrect password is the largest value retrieved.

### `usri4_num_logons`

Type: **DWORD**

The number of times the user logged on successfully to this account. A value of – 1 indicates that the value is unknown. Calls to the
**NetUserAdd** and
**NetUserSetInfo** functions ignore this member.

This member is maintained separately on each backup domain controller (BDC) in the domain. To obtain an accurate value, you must query each BDC in the domain. The number of times the user logged on successfully is the sum of the retrieved values.

### `usri4_logon_server`

Type: **LPWSTR**

A pointer to a Unicode string that contains the name of the server to which logon requests are sent. Server names should be preceded by two backslashes (\\). To indicate that the logon request can be handled by any logon server, specify an asterisk (\\*) for the server name. A **NULL** string indicates that requests should be sent to the domain controller.

For Windows servers,
the [NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function returns \\*.

The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri4_country_code`

Type: **DWORD**

The country/region code for the user's language of choice.

### `usri4_code_page`

Type: **DWORD**

The code page for the user's language of choice.

### `usri4_user_sid`

Type: **PSID**

A pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that contains the security identifier (SID) that uniquely identifies the user. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri4_primary_group_id`

Type: **DWORD**

The relative identifier (RID) of the Primary Global Group for the user. When you call the
**NetUserAdd** function, this member must be DOMAIN_GROUP_RID_USERS (defined in WinNT.h). When you call
**NetUserSetInfo**, this member must be the RID of a global group in which the user is enrolled. For more information, see
[Well-Known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids) and
[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components).

### `usri4_profile`

Type: **LPWSTR**

A pointer to a Unicode string that specifies a path to the user's profile. This value can be a **NULL** string, a local absolute path, or a UNC path.

### `usri4_home_dir_drive`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the drive letter assigned to the user's home directory for logon purposes.

### `usri4_password_expired`

Type: **DWORD**

The password expiration information.

The
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function return zero if the password has not expired (and nonzero if it has).

When you call
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) or
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo), specify a nonzero value in this member to inform users that they must change their password at the next logon. To turn off this message, call
**NetUserSetInfo** and specify zero in this member. Note that you cannot specify zero to negate the expiration of a password that has already expired.

## Remarks

The
**USER_INFO_4** structure can be used with the [NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd),
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo), and
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) functions.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

Note that the
**USER_INFO_4** structure supersedes the
[USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3) structure on Windows XP and later. It is recommended that applications use
the **USER_INFO_4** structure instead of the
**USER_INFO_3** structure with the above functions on Windows XP and later.

## See also

[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd)

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)