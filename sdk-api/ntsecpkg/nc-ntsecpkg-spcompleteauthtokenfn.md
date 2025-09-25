# SpCompleteAuthTokenFn callback function

## Description

The **SpCompleteAuthToken** function completes an authentication token.

The **SpCompleteAuthToken** function is the dispatch function for the
[CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `ContextHandle` [in]

Handle of the context to complete.

### `InputBuffer` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains package-specific information for the context.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists a common reason for failure and the error code that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

SSP/APs must implement the **SpCompleteAuthToken** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpCompleteAuthToken** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken)

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)