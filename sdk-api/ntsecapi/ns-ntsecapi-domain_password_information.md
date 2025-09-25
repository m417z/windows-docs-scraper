# DOMAIN_PASSWORD_INFORMATION structure

## Description

The **DOMAIN_PASSWORD_INFORMATION** structure contains information about a domain's password policy, such as the minimum length for passwords and how unique passwords must be.

It is used in the [MSV1_0_CHANGEPASSWORD_RESPONSE](https://learn.microsoft.com/windows/desktop/SecAuthN/msv1-0-changepassword-response) structure.

## Members

### `MinPasswordLength`

Specifies the minimum length, in characters, of a valid password.

### `PasswordHistoryLength`

Indicates the number of previous passwords saved in the history list. A user cannot reuse a password in the history list.

### `PasswordProperties`

Flags that describe the password properties. They can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **DOMAIN_PASSWORD_COMPLEX**<br><br>0x00000001L | The password must have a mix of at least two of the following types of characters:<br><br>* Uppercase characters<br>* Lowercase characters<br>* Numerals |
| **DOMAIN_PASSWORD_NO_ANON_CHANGE**<br><br>0x00000002L | The password cannot be changed without logging on. Otherwise, if your password has expired, you can change your password and then log on. |
| **DOMAIN_PASSWORD_NO_CLEAR_CHANGE**<br><br>0x00000004L | Forces the client to use a protocol that does not allow the domain controller to get the plaintext password. |
| **DOMAIN_LOCKOUT_ADMINS**<br><br>0x00000008L | Allows the built-in administrator account to be locked out from network logons. |
| **DOMAIN_PASSWORD_STORE_CLEARTEXT**<br><br>0x00000010L | The directory service is storing a plaintext password for all users instead of a hash function of the password. |
| **DOMAIN_REFUSE_PASSWORD_CHANGE**<br><br>0x00000020L | Removes the requirement that the machine account password be automatically changed every week.<br><br>This value should not be used as it can weaken security. |

### `MaxPasswordAge`

Specifies the maximum length of time that a password can remain the same. Passwords older than this must be changed. Because SAM stores relative times as negative values and absolute times as positive numbers, the time is stored as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure with negative values.

The data type for this member is OLD_LARGE_INTEGER if MIDL_PASS is defined.

### `MinPasswordAge`

Specifies the minimum length of time before a password can be changed. Because SAM stores relative times as negative values and absolute times as positive numbers, the time is stored as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure with negative values.

The data type for this member is OLD_LARGE_INTEGER if MIDL_PASS is defined.