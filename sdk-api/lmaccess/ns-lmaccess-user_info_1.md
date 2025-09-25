# USER_INFO_1 structure

## Description

The
**USER_INFO_1** structure contains information about a user account, including account name, password data, privilege level, and the path to the user's home directory.

## Members

### `usri1_name`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of the user account. For the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function, this member is ignored. For more information, see the following Remarks section.

### `usri1_password`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the password of the user indicated by the **usri1_name** member. The length cannot exceed PWLEN bytes. The
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum) and
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) functions return a **NULL** pointer to maintain password security.

By convention, the length of passwords is limited to LM20_PWLEN characters.

### `usri1_password_age`

Type: **DWORD**

The number of seconds that have elapsed since the **usri1_password** member was last changed. The
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

### `usri1_priv`

Type: **DWORD**

The level of privilege assigned to the **usri1_name** member. When you call the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) function, this member must be USER_PRIV_USER. When you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function, this member must be the value returned by the
**NetUserGetInfo** function or the
**NetUserEnum** function. This member can be one of the following values. For more information about user and group account rights, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

| Value | Meaning |
| --- | --- |
| **USER_PRIV_GUEST** | Guest |
| **USER_PRIV_USER** | User |
| **USER_PRIV_ADMIN** | Administrator |

### `usri1_home_dir`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path of the home directory for the user specified in the **usri1_name** member. The string can be **NULL**.

### `usri1_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a comment to associate with the user account. This string can be a **NULL** string, or it can have any number of characters before the terminating null character.

### `usri1_flags`

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
| **UF_LOCKOUT** | The account is currently locked out. You can call the [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function and clear this value to unlock a previously locked account. You cannot use this value to lock a previously unlocked account. |
| **UF_DONT_EXPIRE_PASSWD** | The password should never expire on the account. |
| **UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED** | The user's password is stored under reversible encryption in the Active Directory. |
| **UF_NOT_DELEGATED** | Marks the account as "sensitive"; other users cannot act as delegates of this user account. |
| **UF_SMARTCARD_REQUIRED** | Requires the user to log on to the user account with a smart card. |
| **UF_USE_DES_KEY_ONLY** | Restrict this principal to use only Data Encryption Standard (DES) encryption types for keys. |
| **UF_DONT_REQUIRE_PREAUTH** | This account does not require Kerberos preauthentication for logon. |
| **UF_TRUSTED_FOR_DELEGATION** | The account is enabled for delegation. This is a security-sensitive setting; accounts with this option enabled should be tightly controlled. This setting allows a service running under the account to assume a client's identity and authenticate as that user to other remote servers on the network. |
| **UF_PASSWORD_EXPIRED** | The user's password has expired.<br><br>**Windows 2000:** This value is not supported. |
| **UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION** | The account is trusted to authenticate a user outside of the Kerberos security package and delegate that user through constrained delegation. This is a security-sensitive setting; accounts with this option enabled should be tightly controlled. This setting allows a service running under the account to assert a client's identity and authenticate as that user to specifically configured services on the network.<br><br>**Windows 2000:** This value is not supported. |

The following values describe the account type. Only one value can be set. You cannot change the account type using the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

| Value | Meaning |
| --- | --- |
| **UF_NORMAL_ACCOUNT** | This is a default account type that represents a typical user. |
| **UF_TEMP_DUPLICATE_ACCOUNT** | This is an account for users whose primary account is in another domain. This account provides user access to this domain, but not to any domain that trusts this domain. The User Manager refers to this account type as a local user account. |
| **UF_WORKSTATION_TRUST_ACCOUNT** | This is a computer account for a computer that is a member of this domain. |
| **UF_SERVER_TRUST_ACCOUNT** | This is a computer account for a backup domain controller that is a member of this domain. |
| **UF_INTERDOMAIN_TRUST_ACCOUNT** | This is a permit to trust account for a domain that trusts other domains. |

### `usri1_script_path`

Type: **LPWSTR**

A pointer to a Unicode string specifying the path for the user's logon script file. The script file can be a .CMD file, an .EXE file, or a .BAT file. The string can also be **NULL**.

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