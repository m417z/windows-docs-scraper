# SpFormatCredentialsFn callback function

## Description

Formats [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to be stored in a user object.

## Parameters

### `Credentials` [in]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure containing the credentials to be formatted.

### `FormattedCredentials` [out]

Pointer to a [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure containing the formatted credentials. Allocate memory for the structure using the
[AllocateHeap](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374721(v=vs.85)) function.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

SSP/APs must implement the **SpFormatCredentials** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpFormatCredentials** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[AllocateHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap)

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)