# SaslInitializeSecurityContextW function

## Description

The **SaslInitializeSecurityContext** function wraps a standard call to the [Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function and processes SASL server cookies from the server.

## Parameters

### `phCredential` [in]

A handle to the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) returned by the
[AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function used to build the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). Using the **SaslInitializeSecurityContext** function requires at least OUTBOUND credentials.

### `phContext` [in]

Pointer to a **CtxtHandle** structure. On the first call to the **SaslInitializeSecurityContext** function, this pointer is **NULL**. On the second call, this parameter is a pointer to the handle to the partially formed context returned in the *phNewContext* parameter by the first call.

### `pszTargetName` [in]

Pointer to a Unicode or ANSI string that indicates the target of the context.

### `fContextReq` [in]

Bit flags that indicate the requirements of the context. Flags used for this parameter are prefixed with ISC_REQ_; for example: ISC_REQ_DELEGATE. Specify combinations of the following attributes flags.

| Value | Meaning |
| --- | --- |
| **ISC_REQ_REPLAY_DETECT** | Detect replayed packets. |
| **ISC_REQ_SEQUENCE_DETECT** | Detect messages received out of sequence. |
| **ISC_REQ_CONFIDENTIALITY** | Encrypt messages. |
| **ISC_REQ_STREAM** | Support a stream-oriented connection. |
| **ISC_REQ_EXTENDED_ERROR** | When errors occur, the remote party will be notified. |
| **ISC_REQ_CONNECTION** | The security context will not handle formatting messages. |
| **ISC_REQ_MUTUAL_AUTH** | Client and server will be authenticated. |
| **ISC_REQ_INTEGRITY** | Sign messages and verify signatures. |

For further descriptions of the various attributes, see
[Context Requirements](https://learn.microsoft.com/windows/desktop/SecAuthN/context-requirements).

### `Reserved1` [in]

Reserved value; must be zero.

### `TargetDataRep` [in]

Indicates the data representation, such as byte ordering, on the target. Can be either SECURITY_NATIVE_DREP or SECURITY_NETWORK_DREP.

### `pInput` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains pointers to the buffers supplied as input to the package. The pointer must be **NULL** on the first call to the function. On subsequent calls to the function, it is a pointer to a buffer allocated with enough memory to hold the token returned by the remote peer.

SASL requires a single buffer of type **SECBUFFER_TOKEN** that contains the challenge received from the server.

### `Reserved2` [in]

Reserved value; must be zero.

### `phNewContext` [out]

Pointer to a
[CtxtHandle](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-handles) structure. On the first call to the **SaslInitializeSecurityContext** function, this pointer receives the new context handle. On the second call, *phNewContext* can be the same as the handle specified in the *phContext* parameter.

### `pOutput` [in, out]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains pointers to the
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that receives the output data. If a buffer was typed as SEC_READWRITE in the input, it will be there on output. The system will allocate a buffer for the security token if requested (through ISC_REQ_ALLOCATE_MEMORY) and fill in the address in the buffer descriptor for the security token.

### `pfContextAttr` [out]

Pointer to a variable to receive a set of bit flags that indicate the [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of the established [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). For a description of the various attributes, see
[Context Requirements](https://learn.microsoft.com/windows/desktop/SecAuthN/context-requirements).

Flags used for this parameter are prefixed with ISC_RET_, such as ISC_RET_DELEGATE.

 For a list of valid values, see the *fContextReq* parameter.

Do not check for security-related attributes until the final function call returns successfully. Attribute flags not related to security, such as the ASC_RET_ALLOCATED_MEMORY flag, can be checked before the final return.

**Note** Particular context attributes can change during a negotiation with a remote peer.

### `ptsExpiry` [out, optional]

Pointer to a **TimeStamp** structure that receives the expiration time of the context. It is recommended that the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) always return this value in local time. This parameter is optional and **NULL** should be passed for short-lived clients.

## Return value

If the call is completed successfully, this function returns SEC_E_OK. The following table shows some possible failure return values.

| Return code | Description |
| --- | --- |
| **SEC_E_ALGORITHM_MISMATCH** | Authz processing is not permitted. |
| **SEC_E_INSUFFICIENT_MEMORY** | Not enough memory is available to complete the request. |
| **SEC_E_INVALID_TOKEN** | No Token buffer is located in the *pOutput* parameter, or the message failed to decrypt. |

## Remarks

> [!NOTE]
> The sspi.h header defines SaslInitializeSecurityContext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).