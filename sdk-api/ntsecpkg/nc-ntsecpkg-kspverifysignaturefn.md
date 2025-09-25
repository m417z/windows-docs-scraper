# KspVerifySignatureFn callback function

## Description

Verifies that the message received is correct according to the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly).

The **SpVerifySignature** function is the dispatch function for the
[VerifySignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-verifysignature) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `[in]`

A handle to the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) used to sign the message.

### `Message` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure containing the message to verify.

### `MessageSeqNo` [in]

Sequence number to assign to the message. Sequence numbers are optional and are used as protection against loss and insertion of messages. A value of zero indicates that sequence numbers are not in use.

### `pfQOP` [out]

Pointer to package-specific flags that indicate the quality of protection.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following table lists a common reason for failure and the error code that the function should return.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle is not valid. |

## Remarks

The signature verified by the **SpVerifySignature** function is created by the
[SpMakeSignature](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-kspmakesignaturefn) function, used by a message sender.

SSP/APs must implement the **SpVerifySignature** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpVerifySignature** function is available in the
[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table) structure received from the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## See also

[MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature)

[SECPKG_USER_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_user_function_table)

[SpMakeSignature](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-kspmakesignaturefn)

[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn)

[VerifySignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-verifysignature)