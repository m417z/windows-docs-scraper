# NET_DISPLAY_USER structure

## Description

The
**NET_DISPLAY_USER** structure contains information that an account manager can access to determine information about user accounts.

## Members

### `usri1_name`

Type: **LPWSTR**

A pointer to a Unicode string that specifies the name of the user account.

### `usri1_comment`

Type: **LPWSTR**

A pointer to a Unicode string that contains a comment associated with the user. This string can be a null string, or it can have any number of characters before the terminating null character (MAXCOMMENTSZ).

### `usri1_flags`

Type: **DWORD**

A set of user account flags. This member can be one or more of the following values.

Note that setting user account control flags may require certain [privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) and [control access rights](https://learn.microsoft.com/windows/desktop/AD/control-access-rights). For more information, see the Remarks section of the [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

| Value | Meaning |
| --- | --- |
| **UF_SCRIPT** | The logon script executed. This value must be set. |
| **UF_ACCOUNTDISABLE** | The user's account is disabled. |
| **UF_PASSWD_NOTREQD** | No password is required. |
| **UF_PASSWD_CANT_CHANGE** | The user cannot change the password. |
| **UF_LOCKOUT** | The account is currently locked out (blocked). For the [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function, this value can be cleared to unlock a previously locked account. This value cannot be used to lock a previously unlocked account. |
| **UF_DONT_EXPIRE_PASSWD** | The password will never expire on the account. |
| **UF_TRUSTED_FOR_DELEGATION** | The account is enabled for delegation. This is a security-sensitive setting; accounts with this option enabled should be tightly controlled. This setting allows a service running under the account to assume a client's identity and authenticate as that user to other remote servers on the network. |
| **UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED** | The user's password is stored under reversible encryption in the Active Directory. |
| **UF_NOT_DELEGATED** | The account is marked as "sensitive"; other users cannot act as delegates of this user account. |
| **UF_SMARTCARD_REQUIRED** | The user is required to log on to the user account with a smart card. |
| **UF_USE_DES_KEY_ONLY** | This principal is restricted to use only Data Encryption Standard (DES) encryption types for keys. |
| **UF_DONT_REQUIRE_PREAUTH** | This account does not require Kerberos preauthentication for logon. |
| **UF_PASSWORD_EXPIRED** | The user's password has expired.<br><br>**Windows 2000:** This value is not supported. |
| **UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION** | The account is trusted to authenticate a user outside of the Kerberos security package and delegate that user through constrained delegation. This is a security-sensitive setting; accounts with this option enabled should be tightly controlled. This setting allows a service running under the account to assert a client's identity and authenticate as that user to specifically configured services on the network.<br><br>**Windows XP/2000:** This value is not supported. |

The following values describe the account type. Only one value can be set. You cannot change the account type using the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

| Value | Meaning |
| --- | --- |
| **UF_NORMAL_ACCOUNT** | This is a default account type that represents a typical user. |
| **UF_TEMP_DUPLICATE_ACCOUNT** | This is an account for users whose primary account is in another domain. This account provides user access to this domain, but not to any domain that trusts this domain. The User Manager refers to this account type as a local user account. |
| **UF_WORKSTATION_TRUST_ACCOUNT** | This is a computer account for a workstation or a server that is a member of this domain. |
| **UF_SERVER_TRUST_ACCOUNT** | This is a computer account for a backup domain controller that is a member of this domain. |
| **UF_INTERDOMAIN_TRUST_ACCOUNT** | This is a permit to trust account for a domain that trusts other domains. |

### `usri1_full_name`

Type: **LPWSTR**

A pointer to a Unicode string that contains the full name of the user. This string can be a null string, or it can have any number of characters before the terminating null character.

### `usri1_user_id`

Type: **DWORD**

The relative identifier (RID) of the user. The relative identifier is determined by the accounts database when the user is created. It uniquely defines this user account to the account manager within the domain. For more information about relative identifiers, see
[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components).

### `usri1_next_index`

Type: **DWORD**

The index of the last entry returned by the
[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation) function. Pass this value as the *Index* parameter to
**NetQueryDisplayInformation** to return the next logical entry. Note that you should not use the value of this member for any purpose except to retrieve more data with additional calls to
**NetQueryDisplayInformation**.

## See also

[Get Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/get-functions)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)