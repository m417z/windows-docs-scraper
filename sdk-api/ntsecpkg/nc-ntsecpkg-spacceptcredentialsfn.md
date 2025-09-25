# SpAcceptCredentialsFn callback function

## Description

Called by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) to pass the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) any [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) stored for the authenticated [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This function is called once for each set of credentials stored by the LSA.

## Parameters

### `LogonType` [in]

A
[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type) value indicating the type of logon.

### `AccountName` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure specifying the name of the logged-on account.

### `PrimaryCredentials` [in]

Pointer to a
[SECPKG_PRIMARY_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_primary_cred) structure containing the credentials used to logon. This structure can have **NULL** members.

### `SupplementalCredentials` [in]

Pointer to a
[SECPKG_SUPPLEMENTAL_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_supplemental_cred) structure containing package-specific [supplemental credentials](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

The [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) should save the credentials so that it can service requests for credentials. For additional information, see the
[SpAcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacquirecredentialshandlefn) function.

SSP/APs must implement the **SpAcceptCredentials** function; unlike other SSP/AP functions the name of the function must be **SpAcceptCredentials**.

The LSA accesses the **SpAcceptCredentials** function through the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_PRIMARY_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_primary_cred)

[SECPKG_SUPPLEMENTAL_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_supplemental_cred)

[SECURITY_LOGON_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-security_logon_type)

[SpAcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacquirecredentialshandlefn)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)