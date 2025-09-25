# SpDeleteCredentialsFn callback function

## Description

Deletes [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from a [security package's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) list of [primary](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or [supplemental](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) credentials.

## Parameters

### `CredentialHandle` [in]

A handle to the credentials to delete.

### `Key` [in]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure whose contents indicate which credentials to delete. The information stored in the *Key* parameter is package specific.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

SSP/APs must implement the **SpDeleteCredentials** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpDeleteCredentials** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)