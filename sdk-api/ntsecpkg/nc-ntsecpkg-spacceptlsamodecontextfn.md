# SpAcceptLsaModeContextFn callback function

## Description

Server dispatch function used to create a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) shared by a server and client.

The **SpAcceptLsaModeContext** function is called when the server calls the
[AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `CredentialHandle` [in]

Optional. Handle to the credentials to use for the context.

### `ContextHandle` [in]

Optional. Handle to the current context.

### `InputBuffer` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure containing information from the client.

### `ContextRequirements` [in]

Flags indicating the context requirements. The following table lists the valid values.

| Value | Meaning |
| --- | --- |
| **ASC_REQ_DELEGATE** | The server is allowed to impersonate the client. |
| **ASC_REQ_MUTUAL_AUTH** | Both the client and the server are required to prove their identity. |
| **ASC_REQ_REPLAY_DETECT** | The [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) will support the detection of replayed packets. |
| **ASC_REQ_SEQUENCE_DETECT** | The security context will support the detection of out-of-order messages. |
| **ASC_REQ_USE_SESSION_KEY** | A new [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) must be negotiated. |
| **ASC_REQ_PROMPT_FOR_CREDS** | If the client is an interactive user, the package must, if possible, prompt the user for the appropriate credentials. |
| **ASC_REQ_USE_SUPPLIED_CREDS** | The input buffer contains package-specific credential information which should be used to authenticate the connection. |
| **ASC_REQ_ALLOCATE_MEMORY** | The package must allocate memory. The caller must eventually call the [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function to free memory allocated by the security package. |
| **ASC_REQ_USE_DCE_STYLE** | The caller expects a three-leg mutual authentication transaction. |
| **ASC_REQ_DATAGRAM** | A datagram-type communications channel should be used. For more information, see [Datagram Contexts](https://learn.microsoft.com/windows/desktop/SecAuthN/datagram-contexts). |
| **ASC_REQ_CONNECTION** | A connection-type communications channel should be used. For more information see [Connection-Oriented Contexts](https://learn.microsoft.com/windows/desktop/SecAuthN/connection-oriented-contexts). |
| **ASC_REQ_EXTENDED_ERROR** | If the context fails, generate an error reply message to send back to the client. |
| **ASC_REQ_STREAM** | A stream-type communications channel should be used. For more information, see [Stream Contexts](https://learn.microsoft.com/windows/desktop/SecAuthN/stream-contexts). |
| **ASC_REQ_INTEGRITY** | Buffer integrity can be verified; however, replayed and out-of-sequence messages will not be detected. |

### `TargetDataRep` [in]

Flag indicating the data representation, such as byte ordering, to use. Contains SECURITY_NATIVE_DREP or SECURITY_NETWORK_DREP.

### `NewContextHandle` [out]

Pointer to an **LSA_SEC_HANDLE**. On the first call to
[AcceptSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext), this pointer receives the new context handle. On subsequent calls, *NewContextHandle* can be the same as the handle specified in the *ContextHandle* parameter.

### `OutputBuffer` [out]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that receives information to be sent to the client.

### `ContextAttributes` [out]

Pointer to flags specifying the context attributes that the server supports. For a list of valid values, see the *ContextRequirements* parameter.

### `ExpirationTime` [out]

Pointer to a
[TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) that receives the expiration time for the context.

### `MappedContext` [out]

Pointer to a Boolean value. Set *MappedContext* to **TRUE** if the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) implements the user-mode SSP/AP functions.

### `ContextData` [out]

Optional. Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that receives context-specific data to copy when creating the user-mode [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). Memory for *ContextData* must be allocated using the
[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function. The [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) will free the memory.

## Return value

If the **SpAcceptLsaModeContext** function succeeds and no more processing is required to establish the security context, return STATUS_SUCCESS. If additional processing is required, the function should return SEC_I_CONTINUE_NEEDED.

If the function fails to create the security context for any other reason, return an NTSTATUS code indicating the reason.

## Remarks

[SpInitLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitlsamodecontextfn) is the client-side function for creating a security context.

SSP/APs must implement the **SpAcceptLsaModeContext** function. The actual name given to the implementation is up to the developer.

A pointer to the **SpAcceptLsaModeContext** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap)

[SpInitLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitlsamodecontextfn)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)