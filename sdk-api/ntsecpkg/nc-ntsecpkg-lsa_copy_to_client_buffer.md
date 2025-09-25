# LSA_COPY_TO_CLIENT_BUFFER callback function

## Description

Copies information from a buffer in the current process into a client process's address space.

## Parameters

### `ClientRequest` [in]

Pointer to an opaque
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) data type representing a client request.

### `Length` [in]

Length in bytes of the buffer to be copied.

### `ClientBaseAddress` [in]

Pointer to a buffer that receives the data. This address is the address of the buffer within the client process, not the current process.

### `BufferToCopy` [in]

Pointer to the local buffer whose contents are to be copied into the client address space.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)