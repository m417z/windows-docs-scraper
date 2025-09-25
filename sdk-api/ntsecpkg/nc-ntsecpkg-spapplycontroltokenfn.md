# SpApplyControlTokenFn callback function

## Description

Applies a control token to a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This function is not currently called by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA).

## Parameters

### `ContextHandle` [in]

A handle to the security context to be modified based on the *ControlToken* parameter.

### `ControlToken` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure containing the token to apply to the context.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists common reasons for failure and the error codes that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_TOKEN** | The token is not valid. |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

SSP/APs must implement the **SpApplyControlToken** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpApplyControlToken** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)