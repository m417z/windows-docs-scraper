# SpQueryContextAttributesFn callback function

## Description

The **SpQueryContextAttributes** function retrieves the attributes of a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

The **SpQueryContextAttributes** function is the dispatch function for the
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `ContextHandle` [in]

A handle to the security context.

### `ContextAttribute` [in]

Context attribute to query. For a list of valid values, see the
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

### `Buffer` [out]

Pointer that receives the address of a buffer containing the requested attributes. Memory for the *Buffer* parameter should be allocated with the
[AllocateHeap](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374721(v=vs.85)) function from the
[SECPKG_DLL_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_dll_functions) function table in user-mode. In [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) mode, use the
[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists a common reason for failure and the error code that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

SSP/APs must implement the **SpQueryContextAttributes** function; however, the actual name given to the implementation is up to the developer.

A pointer to the LSA-mode implementation of the **SpQueryContextAttributes** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

A pointer to the user-mode implementation of the **SpQueryContextAttributes** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)