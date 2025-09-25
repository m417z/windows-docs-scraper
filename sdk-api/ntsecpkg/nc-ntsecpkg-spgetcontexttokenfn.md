# SpGetContextTokenFn callback function

## Description

Obtains the token to impersonate. The **SpGetContextToken** function is used by the SSPI
[ImpersonateSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-impersonatesecuritycontext) function to obtain the token to impersonate.

## Parameters

### `ContextHandle` [in]

A handle to the context to impersonate.

### `ImpersonationToken` [out]

Pointer that receives a handle to the token for the specified context. Return the handle to the token without first duplicating the handle or the token.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists a common reason for failure and the error code that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

SSP/APs must implement the **SpGetContextToken** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpGetContextToken** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[ImpersonateSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-impersonatesecuritycontext)

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)