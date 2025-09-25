# InitializeSecurityContextA function

## Description

The **InitializeSecurityContext (General)** function initiates the client side, outbound [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from a credential handle. The function is used to build a security context between the client application and a remote peer. **InitializeSecurityContext (General)** returns a token that the client must pass to the remote peer, which the peer in turn submits to the local security implementation through the
[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) call. The token generated should be considered opaque by all callers.

Typically, the **InitializeSecurityContext (General)** function is called in a loop until a sufficient security context is established.

For information about using this function with a specific [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP), see the following topics.

| Topic | Description |
| --- | --- |
| [InitializeSecurityContext (CredSSP)](https://learn.microsoft.com/windows/win32/secauthn/initializesecuritycontext--credssp) | Initiates the client side, outbound security context from a credential handle by using the Credential Security Support Provider (CredSSP). |
| [InitializeSecurityContext (Digest)](https://learn.microsoft.com/windows/win32/secauthn/initializesecuritycontext--digest) | Initiates the client side, outbound security context from a credential handle by using the Digest security package. |
| [InitializeSecurityContext (Kerberos)](https://learn.microsoft.com/windows/win32/secauthn/initializesecuritycontext--kerberos) | Initiates the client side, outbound security context from a credential handle by using the Kerberos security package. |
| [InitializeSecurityContext (Negotiate)](https://learn.microsoft.com/windows/win32/secauthn/initializesecuritycontext--negotiate) | Initiates the client side, outbound security context from a credential handle by using the Negotiate security package. |
| [InitializeSecurityContext (NTLM)](https://learn.microsoft.com/windows/win32/secauthn/initializesecuritycontext--ntlm) | Initiates the client side, outbound security context from a credential handle by using the NTLM security package. |
| [InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/win32/secauthn/initializesecuritycontext--schannel) | Initiates the client side, outbound security context from a credential handle by using the Schannel security package. |

## Parameters

### `phCredential` [in, optional]

A handle to the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) returned by
[AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea). This handle is used to build the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The **InitializeSecurityContext (General)** function requires at least OUTBOUND credentials.

### `phContext` [in, optional]

A pointer to a [CtxtHandle](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-handles) structure. On the first call to **InitializeSecurityContext (General)**, this pointer is **NULL**. On the second call, this parameter is a pointer to the handle to the partially formed context returned in the *phNewContext* parameter by the first call.

This parameter is optional with the Microsoft Digest SSP and can be set to **NULL**.

When using the Schannel SSP, on the first call to **InitializeSecurityContext (General)**, specify **NULL**. On future calls, specify the token received in the *phNewContext* parameter after the first call to this function.

### `pszTargetName`

TBD

### `fContextReq` [in]

Bit flags that indicate requests for the context. Not all packages can support all requirements. Flags used for this parameter are prefixed with ISC_REQ_, for example, ISC_REQ_DELEGATE. This parameter can be one or more of the following attributes flags.

| Value | Meaning |
| --- | --- |
| **ISC_REQ_ALLOCATE_MEMORY** | The security package allocates output buffers for you. When you have finished using the output buffers, free them by calling the [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function. |
| **ISC_REQ_CONFIDENTIALITY** | Encrypt messages by using the [EncryptMessage](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) function. |
| **ISC_REQ_CONNECTION** | The security context will not handle formatting messages. This value is the default for the Kerberos, Negotiate, and NTLM security packages. |
| **ISC_REQ_DELEGATE** | The server can use the context to authenticate to other servers as the client. The ISC_REQ_MUTUAL_AUTH flag must be set for this flag to work. Valid for Kerberos. Ignore this flag for [constrained delegation](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **ISC_REQ_EXTENDED_ERROR** | When errors occur, the remote party will be notified. |
| **ISC_REQ_HTTP** | Use Digest for HTTP. Omit this flag to use Digest as a SASL mechanism. |
| **ISC_REQ_INTEGRITY** | Sign messages and verify signatures by using the [EncryptMessage](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) and [MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) functions. |
| **ISC_REQ_MANUAL_CRED_VALIDATION** | Schannel must not authenticate the server automatically. |
| **ISC_REQ_MUTUAL_AUTH** | The mutual authentication policy of the service will be satisfied.<br><br>**Caution** This does not necessarily mean that mutual authentication is performed, only that the authentication policy of the service is satisfied. To ensure that mutual authentication is performed, call the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function. |
| **ISC_REQ_NO_INTEGRITY** | If this flag is set, the **ISC_REQ_INTEGRITY** flag is ignored.<br><br>This value is supported only by the Negotiate and Kerberos [security packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **ISC_REQ_REPLAY_DETECT** | Detect replayed messages that have been encoded by using the [EncryptMessage](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) or [MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) functions. |
| **ISC_REQ_SEQUENCE_DETECT** | Detect messages received out of sequence. |
| **ISC_REQ_STREAM** | Support a stream-oriented connection. |
| **ISC_REQ_USE_SESSION_KEY** | A new [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) must be negotiated.<br><br>This value is supported only by the Kerberos [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **ISC_REQ_USE_SUPPLIED_CREDS** | Schannel must not attempt to supply credentials for the client automatically. |

The requested attributes may not be supported by the client. For more information, see the *pfContextAttr* parameter.

For further descriptions of the various attributes, see
[Context Requirements](https://learn.microsoft.com/windows/desktop/SecAuthN/context-requirements).

### `Reserved1` [in]

This parameter is reserved and must be set to zero.

### `TargetDataRep` [in]

The data representation, such as byte ordering, on the target. This parameter can be either SECURITY_NATIVE_DREP or SECURITY_NETWORK_DREP.

This parameter is not used with Digest or Schannel. Set it to zero.

### `pInput` [in, optional]

A pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains pointers to the buffers supplied as input to the package. Unless the client context was initiated by the server, the value of this parameter must be **NULL** on the first call to the function. On subsequent calls to the function or when the client context was initiated by the server, the value of this parameter is a pointer to a buffer allocated with enough memory to hold the token returned by the remote computer.

### `Reserved2` [in]

This parameter is reserved and must be set to zero.

### `phNewContext` [in, out, optional]

A pointer to a
[CtxtHandle](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-handles) structure. On the first call to **InitializeSecurityContext (General)**, this pointer receives the new context handle. On the second call, *phNewContext* can be the same as the handle specified in the *phContext* parameter.

When using the Schannel SSP, on calls after the first call, pass the handle returned here as the *phContext* parameter and specify **NULL** for *phNewContext*.

### `pOutput` [in, out, optional]

A pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that contains pointers to the
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that receives the output data. If a buffer was typed as SEC_READWRITE in the input, it will be there on output. The system will allocate a buffer for the security token if requested (through ISC_REQ_ALLOCATE_MEMORY) and fill in the address in the buffer descriptor for the security token.

When using the Microsoft Digest SSP, this parameter receives the challenge response that must be sent to the server.

When using the Schannel SSP, if the ISC_REQ_ALLOCATE_MEMORY flag is specified, the Schannel SSP will allocate memory for the buffer and put the appropriate information in the [SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc). In addition, the caller must pass in a buffer of type **SECBUFFER_ALERT**. On output, if an alert is generated, this buffer contains information about that alert, and the function fails.

### `pfContextAttr` [out]

A pointer to a variable to receive a set of bit flags that indicate the [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of the established [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). For a description of the various attributes, see
[Context Requirements](https://learn.microsoft.com/windows/desktop/SecAuthN/context-requirements).

Flags used for this parameter are prefixed with ISC_RET, such as ISC_RET_DELEGATE.

 For a list of valid values, see the *fContextReq* parameter.

Do not check for security-related attributes until the final function call returns successfully. Attribute flags that are not related to security, such as the ASC_RET_ALLOCATED_MEMORY flag, can be checked before the final return.

**Note** Particular context attributes can change during negotiation with a remote peer.

### `ptsExpiry` [out, optional]

A pointer to a [TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) structure that receives the expiration time of the context. It is recommended that the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) always return this value in local time. This parameter is optional and **NULL** should be passed for short-lived clients.

There is no expiration time for Microsoft Digest SSP security contexts or [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

#### - pTargetName [in, optional]

A pointer to a null-terminated string that indicates the target of the context. The string contents are [security-package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) specific, as described in the following table. This list is not exhaustive. Additional system SSPs and third party SSPs can be added to a system.

| SSP in use | Meaning |
| --- | --- |
| **Digest** | Null-terminated string that uniquely identifies the URI of the requested resource. The string must be composed of characters that are allowed in a URI and must be representable by the US ASCII code set. Percent encoding can be used to represent characters outside the US ASCII code set. |
| **Kerberos or Negotiate** | [Service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPN) or the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the destination server. |
| **NTLM** | [Service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPN) or the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the destination server. |
| **Schannel/SSL** | Null-terminated string that uniquely identifies the target server. Schannel uses this value to verify the server certificate. Schannel also uses this value to locate the session in the session cache when reestablishing a connection. The cached session is used only if all of the following conditions are met:<br><br>* The target name is the same.<br>* The cache entry has not expired.<br>* The application process that calls the function is the same.<br>* The logon session is the same.<br>* The credential handle is the same. |

## Return value

If the function succeeds, the function returns one of the following success codes.

| Return code | Description |
| --- | --- |
| **SEC_I_COMPLETE_AND_CONTINUE** | The client must call [CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken) and then pass the output to the server. The client then waits for a returned token and passes it, in another call, to [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta). |
| **SEC_I_COMPLETE_NEEDED** | The client must finish building the message and then call the [CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken) function. |
| **SEC_I_CONTINUE_NEEDED** | The client must send the output token to the server and wait for a return token. The returned token is then passed in another call to [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta). The output token can be empty. |
| **SEC_I_INCOMPLETE_CREDENTIALS** | Use with Schannel. The server has requested client authentication, and the supplied credentials either do not include a certificate or the certificate was not issued by a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that is trusted by the server. For more information, see Remarks. |
| **SEC_E_INCOMPLETE_MESSAGE** | Use with Schannel. Data for the whole message was not read from the wire.<br><br>When this value is returned, the *pInput* buffer contains a [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure with a **BufferType** member of **SECBUFFER_MISSING**. The **cbBuffer** member of **SecBuffer** contains a value that indicates the number of additional bytes that the function must read from the client before this function succeeds. While this number is not always accurate, using it can help improve performance by avoiding multiple calls to this function. |
| **SEC_E_OK** | The [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) was successfully initialized. There is no need for another [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) call. If the function returns an output token, that is, if the SECBUFFER_TOKEN in *pOutput* is of nonzero length, that token must be sent to the server. |

If the function fails, the function returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_INSUFFICIENT_MEMORY** | There is not enough memory available to complete the requested action. |
| **SEC_E_INTERNAL_ERROR** | An error occurred that did not map to an SSPI error code. |
| **SEC_E_INVALID_HANDLE** | The handle passed to the function is not valid. |
| **SEC_E_INVALID_TOKEN** | The error is due to a malformed input token, such as a token corrupted in transit, a token of incorrect size, or a token passed into the wrong security package. Passing a token to the wrong package can happen if the client and server did not negotiate the proper security package. |
| **SEC_E_LOGON_DENIED** | The logon failed. |
| **SEC_E_NO_AUTHENTICATING_AUTHORITY** | No authority could be contacted for authentication. The domain name of the authenticating party could be wrong, the domain could be unreachable, or there might have been a trust relationship failure. |
| **SEC_E_NO_CREDENTIALS** | No credentials are available in the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **SEC_E_TARGET_UNKNOWN** | The target was not recognized. |
| **SEC_E_UNSUPPORTED_FUNCTION** | A context attribute flag that is not valid (ISC_REQ_DELEGATE or ISC_REQ_PROMPT_FOR_CREDS) was specified in the *fContextReq* parameter. |
| **SEC_E_WRONG_PRINCIPAL** | The principal that received the authentication request is not the same as the one passed into the *pszTargetName* parameter. This indicates a failure in mutual authentication. |

## Remarks

The caller is responsible for determining whether the final context attributes are sufficient. If, for example, confidentiality was requested, but could not be established, some applications may choose to shut down the connection immediately.

If attributes of the security context are not sufficient, the client must free the partially created context by calling the
[DeleteSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-deletesecuritycontext) function.

The **InitializeSecurityContext (General)** function is used by a client to initialize an outbound context.

For a two-leg security context, the calling sequence is as follows:

1. The client calls the function with *phContext* set to **NULL** and fills in the buffer descriptor with the input message.
2. The security package examines the parameters and constructs an opaque token, placing it in the TOKEN element in the buffer array. If the *fContextReq* parameter includes the ISC_REQ_ALLOCATE_MEMORY flag, the security package allocates the memory and returns the pointer in the TOKEN element.
3. The client sends the token returned in the *pOutput* buffer to the target server. The server then passes the token as an input argument in a call to the [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function.
4. [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) may return a token, which the server sends to the client for a second call to **InitializeSecurityContext (General)** if the first call returned SEC_I_CONTINUE_NEEDED.

For multiple-leg security contexts, such as mutual authentication, the calling sequence is as follows:

1. The client calls the function as described earlier, but the package returns the SEC_I_CONTINUE_NEEDED success code.
2. The client sends the output token to the server and waits for the server's reply.
3. Upon receipt of the server's response, the client calls **InitializeSecurityContext (General)** again, with *phContext* set to the handle that was returned from the last call. The token received from the server is supplied in the *pInput* parameter.

If the server has successfully responded, the security package returns SEC_E_OK and a secure session is established.

If the function returns one of the error responses, the server's response is not accepted, and the session is not established.

If the function returns SEC_I_CONTINUE_NEEDED, SEC_I_COMPLETE_NEEDED, or SEC_I_COMPLETE_AND_CONTINUE, steps 2 and 3 are repeated.

To initialize a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), more than one call to this function may be required, depending on the underlying authentication mechanism as well as the choices specified in the *fContextReq* parameter.

The *fContextReq* and *pfContextAttributes* parameters are bitmasks that represent various context attributes. For a description of the various attributes, see
[Context Requirements](https://learn.microsoft.com/windows/desktop/SecAuthN/context-requirements). The *pfContextAttributes* parameter is valid on any successful return, but only on the final successful return should you examine the flags that pertain to security aspects of the context. Intermediate returns can set, for example, the ISC_RET_ALLOCATED_MEMORY flag.

If the ISC_REQ_USE_SUPPLIED_CREDS flag is set, the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) must look for a SECBUFFER_PKG_PARAMS buffer type in the *pInput* input buffer. This is not a generic solution, but it allows for a strong pairing of security package and application when appropriate.

If ISC_REQ_ALLOCATE_MEMORY was specified, the caller must free the memory by calling the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

For example, the input token could be the challenge from a LAN Manager. In this case, the output token would be the NTLM-encrypted response to the challenge.

The action the client takes depends on the return code from this function. If the return code is SEC_E_OK, there will be no second **InitializeSecurityContext (General)** call, and no response from the server is expected. If the return code is SEC_I_CONTINUE_NEEDED, the client expects a token in response from the server and passes it in a second call to **InitializeSecurityContext (General)**. The SEC_I_COMPLETE_NEEDED return code indicates that the client must finish building the message and call the [CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken) function. The SEC_I_COMPLETE_AND_CONTINUE code incorporates both of these actions.

If **InitializeSecurityContext (General)** returns success on the first (or only) call, then the caller must eventually call the [DeleteSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-deletesecuritycontext) function on the returned handle, even if the call fails on a later leg of the authentication exchange.

The client may call **InitializeSecurityContext (General)** again after it has completed successfully. This indicates to the security package that a reauthentication is wanted.

Kernel mode callers have the following differences: the target name is a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string that must be allocated in virtual memory by using [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc); it must not be allocated from the pool. Buffers passed and supplied in *pInput* and *pOutput* must be in virtual memory, not in the pool.

When using the Schannel SSP, if the function returns SEC_I_INCOMPLETE_CREDENTIALS, check that you specified a valid and trusted certificate in your credentials. The certificate is specified when calling the [AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function. The certificate must be a client authentication certificate issued by a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) trusted by the server. To obtain a list of the CAs trusted by the server, call the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function and specify the SECPKG_ATTR_ISSUER_LIST_EX attribute.

When using the Schannel SSP, after a client application receives an authentication certificate from a CA that is trusted by the server, the application creates a new credential by calling the [AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function and then calling **InitializeSecurityContext (General)** again, specifying the new credential in the *phCredential* parameter.

> [!NOTE]
> The sspi.h header defines InitializeSecurityContext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext)

[AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea)

[CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken)

[DeleteSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-deletesecuritycontext)

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)

[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc)