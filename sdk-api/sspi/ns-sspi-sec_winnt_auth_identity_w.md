# SEC_WINNT_AUTH_IDENTITY_W structure

## Description

Allows you to pass a particular user name and password to the run-time library for the purpose of authentication.

## Members

### `User`

A string that contains the user name.

### `UserLength`

The length, in characters, of the user string, not including the terminating null character.

### `Domain`

A string that contains the domain name or the workgroup name.

### `DomainLength`

The length, in characters, of the domain string, not including the terminating null character.

### `Password`

A string that contains the password of the user in the domain or workgroup. When you have finished using the password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)). For more information about protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `PasswordLength`

The length, in characters, of the password string, not including the terminating null character.

### `Flags`

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SEC_WINNT_AUTH_IDENTITY_ANSI** | The strings in this structure are in ANSI format. |
| **SEC_WINNT_AUTH_IDENTITY_UNICODE** | The strings in this structure are in [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) format. |

## Remarks

When this structure is used with RPC, the structure must remain valid for the lifetime of the binding handle.

The strings may be ANSI or Unicode, depending on the value you assign to the **Flags** member.