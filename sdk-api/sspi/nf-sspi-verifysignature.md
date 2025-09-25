# VerifySignature function

## Description

Verifies that a message signed by using the
[MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) function was received in the correct sequence and has not been modified.

## Parameters

### `phContext` [in]

A handle to the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to use for the message.

### `pMessage` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that references a set of
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures that contain the message and signature to verify. The signature is in a **SecBuffer** structure of type SECBUFFER_TOKEN.

### `MessageSeqNo` [in]

Specifies the sequence number expected by the transport application, if any. If the transport application does not maintain sequence numbers, this parameter is zero.

### `pfQOP` [out]

Pointer to a **ULONG** variable that receives package-specific flags that indicate the quality of protection.

Some security packages ignore this parameter.

## Return value

If the function verifies that the message was received in the correct sequence and has not been modified, the return value is SEC_E_OK.

If the function determines that the message is not correct according to the information in the signature, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_OUT_OF_SEQUENCE** | The message was not received in the correct sequence. |
| **SEC_E_MESSAGE_ALTERED** | The message has been altered. |
| **SEC_E_INVALID_HANDLE** | The context handle specified by *phContext* is not valid. |
| **SEC_E_INVALID_TOKEN** | *pMessage* did not contain a valid SECBUFFER_TOKEN buffer, or contained too few buffers. |
| **SEC_E_QOP_NOT_SUPPORTED** | The quality of protection negotiated between the client and server did not include [integrity](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) checking. |

## Remarks

**Warning**

The **VerifySignature** function will fail if the message was signed using the [RsaSignPssSha512](https://learn.microsoft.com/uwp/api/windows.security.cryptography.core.asymmetricalgorithmnames.rsasignpsssha512) algorithm on a different version of Windows. For example, a message that was signed by calling the [MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) function on Windows 8 will cause the **VerifySignature** function on Windows 8.1 to fail.

## See also

[MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)