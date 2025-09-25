# LSA_DISPATCH_TABLE structure

## Description

The **LSA_DISPATCH_TABLE** structure contains pointers to the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) functions that Windows [authentication packages](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) can call.

The LSA passes this structure to an authentication package when it calls the
[LsaApInitializePackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_initialize_package) function of the package.

## Members

### `CreateLogonSession`

Pointer to the [CreateLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_logon_session) function.

### `DeleteLogonSession`

Pointer to the [DeleteLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_logon_session) function.

### `AddCredential`

Pointer to the
[AddCredential](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_add_credential) function.

### `GetCredentials`

Pointer to the [GetCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_credentials) function.

### `DeleteCredential`

Pointer to the
[DeleteCredential](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_credential) function.

### `AllocateLsaHeap`

Pointer to the
[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function.

### `FreeLsaHeap`

Pointer to the
[FreeLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntlsa/nc-ntlsa-lsa_free_lsa_heap) function.

### `AllocateClientBuffer`

Pointer to the
[AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function.

### `FreeClientBuffer`

Pointer to the
[FreeClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_client_buffer) function.

### `CopyToClientBuffer`

Pointer to the
[CopyToClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_copy_to_client_buffer) function.

### `CopyFromClientBuffer`

Pointer to the [CopyFromClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_copy_from_client_buffer) function.