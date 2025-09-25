# LSA_ALLOCATE_CLIENT_BUFFER callback function

## Description

Allocates a buffer in the client's address space. Buffers allocated in the client's address space are used to hold information returned to the client from an authentication package.

## Parameters

### `ClientRequest` [in]

Pointer to an opaque
[LSA_CLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/plsa-client-request) data structure that contains information about the LSA client's authentication request. A custom authentication package should pass in the value received during the client's call to the function, such as
[LsaApCallPackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_call_package) or
[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user), that returns the output parameter.

### `LengthRequired` [in]

Length of the buffer needed, in bytes.

### `ClientBaseAddress` [out]

Pointer that receives the address of the buffer. This address is the virtual address of the buffer within the client process, not in the current process.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be the following value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_NO_MEMORY** | The client process does not have an adequate memory quota to allocate the buffer. |

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

The authentication package or the client process must later free the buffer. The authentication process can free the buffer by using the
[FreeClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_client_buffer) dispatch routine. The client process can free the buffer by using the
[LsaFreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer) function.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)