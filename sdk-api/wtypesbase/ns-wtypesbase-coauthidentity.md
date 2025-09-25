# COAUTHIDENTITY structure

## Description

Contains a user name and password.

## Members

### `User`

The user's name.

### `UserLength`

The length of the **User** string, without the terminating **NULL**.

### `Domain`

The domain or workgroup name.

### `DomainLength`

The length of the **Domain** string, without the terminating **NULL**.

### `Password`

The user's password in the domain or workgroup.

### `PasswordLength`

The length of the **Password** string, without the terminating **NULL**.

### `Flags`

Indicates whether the strings are Unicode strings.

| Value | Meaning |
| --- | --- |
| **SEC_WINNT_AUTH_IDENTITY_ANSI**<br><br>0x1 | The strings are ANSI strings. |
| **SEC_WINNT_AUTH_IDENTITY_UNICODE**<br><br>0x2 | The strings are Unicode strings. |

## Remarks

COM does not persist the user's password information. For applications that use passwords, please see the documentation on [Cryptography](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-portal) (CryptoAPI).

This structure is equivalent to the [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure.

## See also

[COAUTHINFO](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ns-wtypesbase-coauthinfo)