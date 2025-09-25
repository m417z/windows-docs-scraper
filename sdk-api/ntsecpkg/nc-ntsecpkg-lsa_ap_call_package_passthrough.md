# LSA_AP_CALL_PACKAGE_PASSTHROUGH callback function

## Description

The dispatch function for pass-through logon requests sent to the
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function.

## Parameters

### `ClientRequest` [in]

Pointer to an opaque
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) buffer representing the LSA client's request.

### `ProtocolSubmitBuffer` [in]

Supplies a protocol-specific message to the authentication package.

### `ClientBufferBase` [in]

Provides the address within the client process of the protocol message. This may be necessary to remap pointers within the *ProtocolSubmitBuffer*.

### `SubmitBufferLength` [in]

Specifies the length of the *ProtocolSubmitBuffer* buffer, in bytes.

### `ProtocolReturnBuffer` [out]

Returns the address of the output buffer in the client process. The authentication package is responsible for calling the
[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function to allocate the buffer in the client process. The contents of this buffer are specific to the authentication package.

### `ReturnBufferLength` [out]

Pointer to a **ULONG** that returns the length of the *ProtocolReturnBuffer* buffer, in bytes.

### `ProtocolStatus` [out]

Pointer to an NTSTATUS value. If the function returns STATUS_SUCCESS, *ProtocolStatus* returns a completion status set by the authentication package. *ProtocolStatus* values are specific to the authentication package.

More information about NTSTATUS codes can be found in the Subauth.h file shipped with the Platform SDK.

## Return value

If the function succeeds, return STATUS_SUCCESS. This return value indicates that the authentication package attempted to provide the requested service. Use the *ProtocolStatus* parameter to return the completion status of the service request.

If the authentication package could not process the request and therefore did not attempt to provide the requested service, return an NTSTATUS code indicating the problem. This code can be the following value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_NO_MEMORY** | The client's memory quota is insufficient to allocate the output buffer. |

## Remarks

This function must be implemented by authentication packages.

## See also

[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer)

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)