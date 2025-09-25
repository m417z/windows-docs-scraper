# SpSaveCredentialsFn callback function

## Description

Saves a [supplemental credential](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to the user object.

## Parameters

### `CredentialHandle` [in]

A handle to the credential to save.

### `Credentials` [in]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure containing the credential information to be saved.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

SSP/APs must implement the **SpSaveCredentials** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpSaveCredentials** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)

[SpMarshallSupplementalCreds](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spmarshallsupplementalcredsfn)