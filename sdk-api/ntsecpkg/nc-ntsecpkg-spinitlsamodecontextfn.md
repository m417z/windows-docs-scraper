# SpInitLsaModeContextFn callback function

## Description

The **SpInitLsaModeContext** function is the client dispatch function used to establish a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) between a server and client.

The **SpInitLsaModeContext** function is called when the client calls the
[InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function of the
[Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi).

## Parameters

### `CredentialHandle` [in]

Optional. Handle to the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to use for the context. *CredentialHandle* can be **NULL** if the *ContextHandle* parameter is not **NULL**.

### `ContextHandle` [in]

Optional. Handle to the context to use as the basis for this context. *ContextHandle* can be **NULL** if the *CredentialHandle* parameter is not **NULL**.

### `TargetName` [in]

Optional. Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the target of the context. The content of *TargetName* is package-specific and is not interpreted by the LSA.

### `ContextRequirements` [in]

Flags indicating the context attributes required by the client. The actual context attributes are returned in the *ContextAttributes* parameter.

The following table lists the valid values.

| Value | Meaning |
| --- | --- |
| **ISC_REQ_DELEGATE** | The server is allowed to impersonate the client. |
| **ISC_REQ_MUTUAL_AUTH** | Both the client and the server are required to prove their identity. |
| **ISC_REQ_REPLAY_DETECT** | The [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) will support the detection of replayed packets. |
| **ISC_REQ_SEQUENCE_DETECT** | The security context will support the detection of out-of-order messages. |
| **ISC_REQ_USE_SESSION_KEY** | A new [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) must be negotiated. |
| **ISC_REQ_PROMPT_FOR_CREDS** | If the client is an interactive user, the package must, if possible, prompt the user for the appropriate credentials. |
| **ISC_REQ_USE_SUPPLIED_CREDS** | The input buffer contains package-specific credential information which should be used to authenticate the connection. |
| **ISC_REQ_ALLOCATE_MEMORY** | The package must allocate memory. The caller must eventually call the [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function to free memory allocated by the package. |
| **ISC_REQ_USE_DCE_STYLE** | The caller expects a three-leg mutual authentication transaction. |
| **ISC_REQ_DATAGRAM** | A datagram-type communications channel should be used. For more information, see [Datagram Contexts](https://learn.microsoft.com/windows/desktop/SecAuthN/datagram-contexts). |
| **ISC_REQ_CONNECTION** | A connection-type communications channel should be used. For more information see [Connection-Oriented Contexts](https://learn.microsoft.com/windows/desktop/SecAuthN/connection-oriented-contexts). |
| **ISC_REQ_EXTENDED_ERROR** | If the context fails, generate an error reply message to send back to the client. |
| **ISC_REQ_STREAM** | A stream-type communications channel should be used. For more information, see [Stream Contexts](https://learn.microsoft.com/windows/desktop/SecAuthN/stream-contexts). |
| **ISC_REQ_INTEGRITY** | Buffer integrity is verified; however, replayed and out-of-sequence messages will not be detected. |

### `TargetDataRep` [in]

Flag indicating the data representation, such as byte ordering, on the target. Contains SECURITY_NATIVE_DREP or SECURITY_NETWORK_DREP.

### `InputBuffers` [in]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure containing the previous reply message from the server. The first time this function is called the *InputBuffers* parameter is **NULL**.

### `NewContextHandle` [out]

Pointer that receives a handle to the new [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). When you have finished using the security context, release the handle by calling the [SpDeleteContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-kspdeletecontextfn) function.

### `OutputBuffers` [out]

Pointer to a
[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure containing the security token to pass back to the server.

### `ContextAttributes` [out]

Pointer to flags specifying the attributes of the new context. The client requests a set of attributes using the *ContextRequirements* parameter. If the *ContextRequirements* flags do not match the *ContextAttributes* flags, the client must decide whether to continue or terminate. For a complete list of the valid flags, see
[Context Requirements](https://learn.microsoft.com/windows/desktop/SecAuthN/context-requirements).

### `ExpirationTime` [out]

Pointer to a
[TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) that receives the expiration time for the new context.

### `MappedContext` [out]

Pointer to a Boolean value. Set *MappedContext* to **TRUE** if the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) implements the user-mode SSP/AP functions.

### `ContextData` [out]

Pointer to a
[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure that receives the data to copy when creating a user-mode security context. Allocate memory for *ContextData* using the
[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function. The LSA will free the memory.

## Return value

If the function succeeds and no more processing is required, return STATUS_SUCCESS. If processing is not complete, the function should return SEC_I_CONTINUE_NEEDED. When this value is returned, the caller must call the
[InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function again.

If the function fails to create the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for any other reason, it should return an NTSTATUS code indicating the reason it failed.

## Remarks

The
[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn) function is the server-side function for creating a context.

SSP/APs must implement the **SpInitLsaModeContext** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpInitLsaModeContext** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap)

[InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta)

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpAcceptLsaModeContext](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptlsamodecontextfn)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)

[TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp)