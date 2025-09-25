# SECURITY_LOGON_SESSION_DATA structure

## Description

The **SECURITY_LOGON_SESSION_DATA** structure contains information about a [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

This structure is used by the
[LsaGetLogonSessionData](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsagetlogonsessiondata) function.

## Members

### `Size`

The size of the structure, in bytes.

### `LogonId`

A [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) that identifies a logon session.

### `UserName`

An
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the account name of the [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) that owns the logon session.

### `LogonDomain`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the domain used to authenticate the owner of the logon session.

### `AuthenticationPackage`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) used to authenticate the owner of the logon session.

### `LogonType`

A
[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) value that identifies the logon method.

### `Session`

A Terminal Services session identifier. This member may be zero.

### `Sid`

A pointer to the user's [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

### `LogonTime`

The time the session owner logged on.

### `LogonServer`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the server used to authenticate the owner of the logon session.

### `DnsDomainName`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the DNS name for the owner of the logon session.

### `Upn`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) for the owner of the logon session.

### `UserFlags`

The user flags for the logon session.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

| Value | Meaning |
| --- | --- |
| **LOGON_OPTIMIZED**<br><br>0x4000 | The logon is an optimized logon session. |
| **LOGON_WINLOGON**<br><br>0x8000 | The logon was created for Winlogon. |
| **LOGON_PKINIT**<br><br>0x10000 | The Kerberos PKINIT extension was used to authenticate the user in this logon session. |
| **LOGON_NOT_OPTIMIZED**<br><br>0x20000 | Optimized logon has been disabled for this account. |

### `LastLogonInfo`

An [LSA_LAST_INTER_LOGON_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-lsa_last_inter_logon_info) structure that contains the information on the last logon session.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `LogonScript`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the script used for logging on.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `ProfilePath`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the path to the user's profile.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `HomeDirectory`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the home directory for the logon session.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `HomeDirectoryDrive`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the drive location of the home directory of the logon session.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `LogoffTime`

The time stamp of when the session user logged off.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `KickOffTime`

The time that the logon session must end.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `PasswordLastSet`

The time when the user last changed the password. **Note** It is up to the Authentication Package to initialize this value and it may not be initialized.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `PasswordCanChange`

The password can be changed during the logon session.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

### `PasswordMustChange`

The password must be changed during the logon session.

**Windows Server 2003 R2, Windows XP with SP1 and earlier, Windows Server 2003 and Windows XP:** This member is not supported.

## Remarks

This structure is allocated by the LSA. When the structure is no longer required, free it by using the
[LSAFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer) function.