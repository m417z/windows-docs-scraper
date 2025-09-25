# SECPKG_PRIMARY_CRED structure

## Description

The **SECPKG_PRIMARY_CRED** structure contains the [primary credentials](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This structure is used by the
[LsaApLogonUserEx2](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex2) and
[SpAcceptCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptcredentialsfn) functions.

## Members

### `LogonId`

The [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

### `DownlevelName`

A
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the Security Accounts Manager account name.

### `DomainName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the NetBIOS domain name where the account is located.

### `Password`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the logon password. When you have finished using the password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)). For more information on protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `OldPassword`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the old password. When you have finished using the old password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)).

### `UserSid`

Pointer to the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `Flags`

The set of [primary credentials](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) flags. The following table lists the valid values for the **Flags** member.

| Value | Meaning |
| --- | --- |
| **PRIMARY_CRED_CLEAR_PASSWORD** | The passwords are in plaintext. |
| **PRIMARY_CRED_OWF_PASSWORD** | The passwords are encrypted using a one-way function. |
| **PRIMARY_CRED_UPDATE** | This is a change of existing credentials. |
| **PRIMARY_CRED_CACHED_LOGON** | The credentials were obtained from a cached logon. For more information, see Remarks. |

### `DnsDomainName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the DNS domain name where the user account is located, if known.

### `Upn`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the user principal name (UPN), if known.

### `LogonServer`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name of the server that processed the logon.

### `Spare1`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure. Reserved.

### `Spare2`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure. Reserved.

### `Spare3`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure. Reserved.

### `Spare4`

A [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure. Reserved.

## Remarks

For cached logons, the RPC identifier of the package that performs the logon is identified by shifting the **Flags** member to the right by using the PRIMARY_CRED_LOGON_PACKAGE_SHIFT constant defined below.

```cpp
#define PRIMARY_CRED_LOGON_PACKAGE_SHIFT 24

```