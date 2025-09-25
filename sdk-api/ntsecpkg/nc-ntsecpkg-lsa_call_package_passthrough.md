# LSA_CALL_PACKAGE_PASSTHROUGH callback function

## Description

The **CallPackagePassthrough** function is used to call another [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to access its services.

## Parameters

### `AuthenticationPackage` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the package to call.

### `ClientBufferBase` [in]

The base address of the input buffer, in the client's address space.

### `ProtocolSubmitBuffer` [in]

Pointer to the input buffer.

### `SubmitBufferLength` [in]

Size of the *ProtocolSubmitBuffer* parameter in bytes.

### `ProtocolReturnBuffer` [out]

Pointer to the output buffer.

### `ReturnBufferLength` [out]

Pointer to a variable that receives the size of the *ProtocolReturnBuffer* parameter in bytes.

### `ProtocolStatus` [out]

Pointer to a variable that receives the status code returned by the package.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed. The following table lists a common reason for failure and the error code that the function returns.

| Return code | Description |
| --- | --- |
| **STATUS_NO_SUCH_PACKAGE** | The *AuthenticationPackage* parameter does not contain the name of a valid SSP/AP. |

## Remarks

The [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) does not examine or alter any of the function arguments.

A pointer to the **CallPackagePassthrough** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[CallPackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_package)

[CallPackageEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_packageex)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)