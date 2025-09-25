# CompleteAuthToken function

## Description

The **CompleteAuthToken** function completes an authentication token. This function is used by protocols, such as DCE, that need to revise the security information after the transport application has updated some message parameters.

This function is supported only by the Digest [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

**CompleteAuthToken** is used on the server side only.

## Parameters

### `phContext` [in]

A handle of the context that needs to be completed.

### `pToken` [in]

A pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains the buffer descriptor for the entire message.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle that was passed to the function is not valid. |
| **SEC_E_INVALID_TOKEN** | The token that was passed to the function is not valid. |
| **SEC_E_OUT_OF_SEQUENCE** | The client's security context was located, but the message number is incorrect. This return value is used with the Digest SSP. |
| **SEC_E_MESSAGE_ALTERED** | The client's security context was located, but the client's message has been tampered with. This return value is used with the Digest SSP. |
| **SEC_E_INTERNAL_ERROR** | An error occurred that did not map to an SSPI error code. |

## Remarks

The client of a transport application calls the **CompleteAuthToken** function to allow the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to update a checksum or similar operation after all the protocol headers have been updated by the transport application. The client calls this function only if the
[InitializeSecurityContext (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) call returned SEC_I_COMPLETE_NEEDED or SEC_I_COMPLETE_AND_CONTINUE.

## See also

[InitializeSecurityContext (Digest)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc)