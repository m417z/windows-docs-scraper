# LSA_UPDATE_PRIMARY_CREDENTIALS callback function

## Description

Provides a mechanism for one [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to notify other packages that the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for a logon [session](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) have changed.

## Parameters

### `PrimaryCredentials` [in]

Pointer to a
[SECPKG_PRIMARY_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_primary_cred) structure containing the [primary credentials](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `Credentials` [in, optional]

Optional. Pointer to a
[SECPKG_SUPPLEMENTAL_CRED_ARRAY](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_supplemental_cred_array) structure containing the [supplemental credentials](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed.

## Remarks

To notify packages about the changed credentials, the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) calls the
[SpAcceptCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptcredentialsfn) function implementation in each package.

A pointer to the **UpdateCredentials** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SECPKG_PRIMARY_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_primary_cred)

[SECPKG_SUPPLEMENTAL_CRED_ARRAY](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_supplemental_cred_array)

[SpAcceptCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptcredentialsfn)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)