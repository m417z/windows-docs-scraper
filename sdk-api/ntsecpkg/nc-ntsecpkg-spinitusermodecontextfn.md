# SpInitUserModeContextFn callback function

## Description

The **SpInitUserModeContext** function creates a user-mode [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from a packed [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA)-mode context.

## Parameters

### `ContextHandle` [in]

A handle to the LSA-mode context returned from the
[SpInitLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitlsamodecontextfn) or
[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn) function.

### `PackedContext` [in]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that contains the [serialized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) context data. Use the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function to free memory allocated for this structure.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists a common reason for failure and the error code that the function should return.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory to create the context. |

## Remarks

The **SpInitUserModeContext** function is called after a security context has been created by the security package, if the *MappedContext* parameter of the
[SpInitLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitlsamodecontextfn) or
[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn) is set to **TRUE**. The package-specific context data should contain the information required to determine which function resulted in the call to **SpInitUserModeContext**.

SSP/APs must implement the **SpInitUserModeContext** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpInitUserModeContext** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn)

[SpInitLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitlsamodecontextfn)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)