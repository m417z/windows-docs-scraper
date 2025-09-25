# KspMakeSignatureFn callback function

## Description

The **SpMakeSignature** function generates a [signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) based on the specified message and [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

The **SpMakeSignature** function is the dispatch function for the
[MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `ContextId` [in]

A handle to the security context to be used to generate the message signature.

### `fQOP` [in]

Specifies package-specific flags that indicate the quality of protection. A security package can use this parameter to support the selection of cryptographic algorithms

### `Message` [in]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure. On input, the structure contains the message to be signed.

### `MessageSeqNo` [in]

Sequence number to assign to the message. Sequence numbers are optional and are used as protection against loss and insertion of messages. A value of zero indicates that sequence numbers are not in use.

#### - MessageBuffers
## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following lists a common reason for failure and the error code that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

The counterpart to the **SpMakeSignature** function is the
[SpVerifySignature](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-kspverifysignaturefn) function, used to verify signatures at the receiving end.

SSP/APs must implement the **SpMakeSignature** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpMakeSignature** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature)

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)

[SpVerifySignature](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-kspverifysignaturefn)