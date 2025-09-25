# LSA_DUPLICATE_HANDLE callback function

## Description

The **DuplicateHandle** function creates a duplicate handle. The returned duplicate is in the caller's process space.

## Parameters

### `SourceHandle` [in]

A handle to duplicate.

### `DestionationHandle` [out]

Pointer that receives the address of a duplicate of the *SourceHandle* handle. The duplicate handle is in the caller's process space. When you have finished using the handle, close it by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed.

## Remarks

A pointer to the **DuplicateHandle** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)