# LSA_AUDIT_LOGON callback function

## Description

The **AuditLogon** function is used to audit a logon attempt.

## Parameters

### `Status` [in]

Status of the logon attempt.

### `SubStatus` [in]

Additional status information for the logon attempt.

### `AccountName` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the account name used in the logon attempt.

### `AuthenticatingAuthority` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the authority that authenticated the logon, normally the operating system domain name.

### `WorkstationName` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the workstation used to attempt the logon.

### `UserSid` [in, optional]

Pointer to the SID of the [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) attempting to logon.

### `LogonType` [in]

A
[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) value indicating the type of logon.

### `TokenSource` [in]

Pointer to a
[TOKEN_SOURCE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_source) structure that specifies the source for the user token. This value must include the package name.

### `LogonId` [in]

Pointer to the [logon session identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly). *LogonId* is valid only if the logon attempt was successful.

## Remarks

A pointer to the **AuditLogon** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)