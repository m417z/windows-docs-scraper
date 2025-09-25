# CredFreeCredentialsFn callback function

## Description

Frees memory used to store credentials used by a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `Count` [in]

The number of elements in the *Credentials* array.

### `Credentials` [in, out]

A pointer to a pointer that, on input, points to an array of [ENCRYPTED_CREDENTIALW](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-encrypted_credentialw) structures to be freed.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code that indicates the reason it failed.

## Remarks

A pointer to the **CrediFreeCredentials** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)