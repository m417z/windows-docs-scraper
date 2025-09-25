# SpFreeCredentialsHandleFn callback function

## Description

Frees [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) acquired by calling the
[SpAcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacquirecredentialshandlefn) function.

## Parameters

### `CredentialHandle` [in]

A handle to the credentials to free.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists a common reason for failure and the error code that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

SSP/APs must implement the **SpFreeCredentialsHandle** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpFreeCredentialsHandle** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpAcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacquirecredentialshandlefn)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)