# SpExportSecurityContextFn callback function

## Description

Exports a security context to another process.

The **SpExportSecurityContext** function is the dispatch function for the
[ExportSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-exportsecuritycontext) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `phContext` [in]

A handle to the security context to export.

### `fFlags` [in]

Optional. Specifies context duplication options. The following table lists the valid values which are defined in Sspi.h.

| Value | Meaning |
| --- | --- |
| **SECPKG_CONTEXT_EXPORT_RESET_NEW** | New context is reset to initial state. |
| **SECPKG_CONTEXT_EXPORT_DELETE_OLD** | Old context is deleted during export. |

### `pPackedContext` [out]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure containing the [serialized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) context. Resources should be allocated using the
[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function, and freed by the caller using the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

### `pToken` [out]

Optional. Pointer to a handle that receives the context's token.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

To import a previously exported security context use the
[SpImportSecurityContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spimportsecuritycontextfn) function.

SSP/APs must implement the **SpExportSecurityContext** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpExportSecurityContext** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpImportSecurityContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spimportsecuritycontextfn)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)