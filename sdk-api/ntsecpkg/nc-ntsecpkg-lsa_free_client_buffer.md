# LSA_FREE_CLIENT_BUFFER callback function

## Description

Frees a client buffer previously allocated with the
[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function.

## Parameters

### `ClientRequest` [in]

Pointer to an opaque
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) data type containing information about the LSA client's request.

### `ClientBaseAddress` [in]

Optional. Pointer to the buffer to be freed. This address is the virtual address of the buffer within the client process, not in the current process. If **NULL** is passed, no memory is freed. This allows the client to pass in a value returned to it by the LSA without knowing whether the LSA actually allocated a buffer.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

Because this function frees pages in the client's process, it must be called with great care. Calling this function with an address that is not valid can cause the client process to crash.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)