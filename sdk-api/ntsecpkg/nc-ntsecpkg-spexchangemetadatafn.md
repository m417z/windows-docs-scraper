# SpExchangeMetaDataFn callback function

## Description

Sends metadata to a [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The metadata sent by this function is obtained by a previous call to the [SpQueryMetaDataFn](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spquerymetadatafn) function.

## Parameters

### `CredentialHandle` [in]

A handle to the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to use for the security context. If the *ContextHandle* parameter points to **NULL** on input, this function uses the value of this parameter to create a security context.

The value of this parameter cannot be **NULL** if the *ContextHandle* parameter points to **NULL** on input.

### `TargetName` [in, optional]

A pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that contains the name of the target of the context.

### `ContextRequirements` [in]

Flags that indicate the context attributes required by the client.

The following are valid values. Values can be combined by using a logical **OR** operation.

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

### `MetaDataLength` [in]

The size, in characters, of the *MetaData* buffer.

### `MetaData` [in]

The metadata to send.

### `ContextHandle` [in, out]

A handle to the security handle to use. If this parameter points to **NULL** on input, this function allocates and initializes a security context by using the values of the *CredentialHandle* and *TargetName* parameters.

If this parameter points to **NULL** on input, the *CredentialHandle* cannot be **NULL**.

## Return value

If the function succeeds, return **STATUS_SUCCESS**, or an informational status code.

If the function fails, return an **NTSTATUS** error code that indicates the reason it failed. For more information, see Remarks.

## Remarks

A pointer to the **SpExchangeMetaDataFn** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.