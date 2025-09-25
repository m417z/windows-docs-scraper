# LSA_CALL_PACKAGE callback function

## Description

The **CallPackage** function is used to call another [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to access its services.

## Parameters

### `AuthenticationPackage` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the package to call.

### `ProtocolSubmitBuffer` [in]

Pointer to the input buffer. The content of this buffer is package-specific.

### `SubmitBufferLength` [in]

Size of the *ProtocolSubmitBuffer* parameter in bytes.

### `ProtocolReturnBuffer` [out]

Pointer that receives the address of the output buffer. The content of this buffer is package-specific.

### `ReturnBufferLength` [out]

Pointer to a variable that receives the size of the *ProtocolReturnBuffer* parameter in bytes.

### `ProtocolStatus` [out]

Pointer to a variable that receives the status code returned by the called package.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed. The following table lists a common reason for failure and the error code that the function returns.

| Return code | Description |
| --- | --- |
| **STATUS_NO_SUCH_PACKAGE** | The *AuthenticationPackage* parameter does not contain the name of a valid [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |

## Remarks

A pointer to the **CallPackage** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[CallPackageEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_packageex)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)