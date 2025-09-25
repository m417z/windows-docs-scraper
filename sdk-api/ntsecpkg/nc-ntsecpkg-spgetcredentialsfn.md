# SpGetCredentialsFn callback function

## Description

The **SpGetCredentials** function retrieves the [primary](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and [supplemental credentials](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from the user object.

## Parameters

### `CredentialHandle` [in]

A handle to the credentials to be retrieved.

### `Credentials` [out]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that receives the credentials.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code indicating the reason it failed. The following lists common reasons for failure and the error codes that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INSUFFICIENT_MEMORY** | There is not sufficient memory to retrieve the credentials. |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

SSP/APs must implement the **SpGetCredentials** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpGetCredentials** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)