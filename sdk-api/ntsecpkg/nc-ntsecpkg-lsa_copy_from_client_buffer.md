# LSA_COPY_FROM_CLIENT_BUFFER callback function

## Description

Copies information from the address space of a client process into a buffer in the current process.

## Parameters

### `ClientRequest` [in]

Pointer to an opaque
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) data structure that contains information about the LSA client's authentication request.

### `Length` [in]

Length of the buffer to be copied, in bytes.

### `BufferToCopy` [in]

Pointer to the local buffer into which the data is to be copied.

### `ClientBaseAddress` [in]

Pointer to the client buffer whose contents are to be copied. This address is the address of the buffer within the client process, not the current process.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)