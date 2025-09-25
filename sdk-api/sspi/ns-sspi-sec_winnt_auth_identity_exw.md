## Description

The **SEC_WINNT_AUTH_IDENTITY_EX** structure contains information about a user. Both an ANSI and [Unicode](https://msdn.microsoft.com/264f6cb6-36c6-4cdb-b7bb-a5dbd332adcb) form of this structure are provided.

## Members

### `Version`

An unsigned long that indicates the version number of the structure.

### `Length`

An unsigned long that indicates the length, in bytes, of the structure.

### `User`

A Unicode or ANSI string that contains the name of the user account.

### `UserLength`

The length, in characters, of the **User** string.

### `Domain`

A Unicode or ANSI string that contains the name of the domain for the user account.

### `DomainLength`

The length, in characters, of the **Domain** string.

### `Password`

A Unicode or ANSI string that contains the user password in plaintext. When you have finished using the password, remove the sensitive information from memory by calling the [SecureZeroMemory](https://msdn.microsoft.com/2c4090a6-025b-4b7b-8f31-7e744ad51b39) function. For more information about protecting the password, see [Handling Passwords](https://msdn.microsoft.com/1d810f71-9bf5-4c5c-a573-c35081f604cf).

### `PasswordLength`

The length, in characters, of the **Password** string.

### `Flags`

An unsigned long flag that indicates the type used by negotiable [security packages](https://msdn.microsoft.com/3e9d7672-2314-45c8-8178-5a0afcfd0c50).

| Value | Meaning |
| --- | --- |
| **SEC_WINNT_AUTH_IDENTITY_MARSHALLED** | All data is in one buffer. |
| **SEC_WINNT_AUTH_IDENTITY_ONLY** | Used with the [Kerberos](https://msdn.microsoft.com/f17042c3-ba1a-408f-af55-5f171b0dee33) [security support provider](https://msdn.microsoft.com/3e9d7672-2314-45c8-8178-5a0afcfd0c50) (SSP). Credentials are for identity only. The Kerberos package is directed to not include authorization data in the ticket. |
| **SEC_WINNT_AUTH_IDENTITY_ANSI** | Credentials are in ANSI form. |
| **SEC_WINNT_AUTH_IDENTITY_UNICODE** | Credentials are in Unicode form. |

### `PackageList`

A Unicode or ANSI string that contains a comma-separated list of names of security packages that are available when using the [Microsoft Negotiate](https://msdn.microsoft.com/3aa7e979-8b55-416d-bed1-28296055d38e) provider.

Set this to "!ntlm" to specify that the [NTLM](https://msdn.microsoft.com/35a38858-d36f-45c9-95f4-2541a182f5ac) package is not to be used.

### `PackageListLength`

The length, in characters, of the **PackageList** string.

## Remarks

Note that when this structure is used with RPC, the structure must remain valid for the lifetime of the binding handle.