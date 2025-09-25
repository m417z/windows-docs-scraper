# NETLOGON_LOGON_IDENTITY_INFO structure

## Description

The **NETLOGON_LOGON_IDENTITY_INFO** structure is used to pass information about a user for logon [subauthentication](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

It is used by
[Msv1_0SubAuthenticationRoutine](https://learn.microsoft.com/windows/desktop/api/subauth/nf-subauth-msv1_0subauthenticationroutine) and
[Msv1_0SubAuthenticationFilter](https://learn.microsoft.com/windows/desktop/api/subauth/nf-subauth-msv1_0subauthenticationfilter).

## Members

### `LogonDomainName`

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the logon domain. The specified domain name must be a domain that is trusted by this machine. If the logon domain is unknown, such as a down-level client that does not supply this information, this member should be **NULL**.

### `ParameterControl`

Specifies attributes of the other function parameters.

| Value | Meaning |
| --- | --- |
| **CLEARTEXT_PASSWORD_ALLOWED** | Specifies that **CaseSensitiveChallengeResponse** and **CaseInsensitiveChallengeResponse** are allowed to be the user's [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) password. |

### `LogonId`

Uniquely identifies the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

### `UserName`

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) identifying the account name of the user attempting to log on.

### `Workstation`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) identifying the workstation from which the user is attempting to log on. **NULL** indicates that the workstation identity is unknown.