# MakeSignature function

## Description

The **MakeSignature** function generates a cryptographic checksum of the message, and also includes sequencing information to prevent message loss or insertion. **MakeSignature** allows the application to choose between several cryptographic algorithms, if supported by the chosen mechanism. The **MakeSignature** function uses the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) referenced by the context handle.

This function is not supported by the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

## Parameters

### `phContext` [in]

A handle to the security context to use to sign the message.

### `fQOP` [in]

[Package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)-specific flags that indicate the quality of protection. A security package can use this parameter to enable the selection of cryptographic algorithms.

When using the Digest SSP, this parameter must be set to zero.

### `pMessage` [in, out]

A pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure. On input, the structure references one or more
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures that contain the message to be signed. The function does not process buffers with the SECBUFFER_READONLY_WITH_CHECKSUM attribute.

The [SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure also references a [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure of type SECBUFFER_TOKEN that receives the signature.

When the Digest SSP is used as an HTTP authentication protocol, the buffers should be configured as follows.

| Buffer #/buffer type | Meaning |
| --- | --- |
| **0**<br><br>SECBUFFER_TOKEN | Empty. |
| **1**<br><br>SECBUFFER_PKG_PARAMS | Method. |
| **2**<br><br>SECBUFFER_PKG_PARAMS | URL. |
| **3**<br><br>SECBUFFER_PKG_PARAMS | HEntity. For more information, see [Input Buffers for the Digest Challenge Response](https://learn.microsoft.com/windows/desktop/SecAuthN/input-buffers-for-the-digest-challenge-response). |
| **4**<br><br>SECBUFFER_PADDING | Empty. Receives the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly). |

When the Digest SSP is used as an SASL mechanism, the buffers should be configured as follows.

| Buffer #/buffer type | Meaning |
| --- | --- |
| **0**<br><br>SECBUFFER_TOKEN | Empty. Receives the signature. This buffer must be large enough to hold the largest possible signature. Determine the size required by calling the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function and specifying SECPKG_ATTR_SIZES. Check the returned [SecPkgContext_Sizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sizes) structure member **cbMaxSignature**. |
| **1**<br><br>SECBUFFER_DATA | Message to be signed. |
| **2**<br><br>SECBUFFER_PADDING | Empty. |

### `MessageSeqNo` [in]

The sequence number that the transport application assigned to the message. If the transport application does not maintain sequence numbers, this parameter is zero.

When using the Digest SSP, this parameter must be set to zero. The Digest SSP manages sequence numbering internally.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_I_RENEGOTIATE** | The remote party requires a new handshake sequence or the application has just initiated a shutdown. Return to the negotiation loop and call [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) or [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) again. An empty input buffer is passed in the first call. |
| **SEC_E_INVALID_HANDLE** | The context handle specified by *phContext* is not valid. |
| **SEC_E_INVALID_TOKEN** | *pMessage* did not contain a valid SECBUFFER_TOKEN buffer or contained too few buffers. |
| **SEC_E_OUT_OF_SEQUENCE** | The [nonce](https://learn.microsoft.com/windows/desktop/SecGloss/n-gly) count is out of sequence. |
| **SEC_E_NO_AUTHENTICATING_AUTHORITY** | The [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (*phContext*) must be revalidated. |
| **STATUS_INVALID_PARAMETER** | The nonce count is not numeric. |
| **SEC_E_QOP_NOT_SUPPORTED** | The quality of protection negotiated between the client and server did not include [integrity](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) checking. |

## Remarks

The **MakeSignature** function generates a signature that is based on the message and the [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

The [VerifySignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-verifysignature) function verifies the messages signed by the **MakeSignature** function.

If the transport application created the security context to support sequence detection and the caller provides a sequence number, the function includes this information in the signature. This protects against reply, insertion, and suppression of messages. The [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) incorporates the sequence number passed down from the transport application.

## See also

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)

[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc)

[VerifySignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-verifysignature)