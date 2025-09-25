# LSA_SECPKG_FUNCTION_TABLE structure

## Description

The **LSA_SECPKG_FUNCTION_TABLE** structure contains pointers to the LSA functions that a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) can call. The [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) passes this structure to a security package when it calls the package's
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## Members

### `CreateLogonSession`

Pointer to the [CreateLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_logon_session) function.

### `DeleteLogonSession`

Pointer to the [DeleteLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_logon_session) function.

### `AddCredential`

Pointer to the [AddCredential](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_add_credential) function.

### `GetCredentials`

Pointer to the [GetCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_credentials) function.

### `DeleteCredential`

Pointer to the [DeleteCredential](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_credential) function.

### `AllocateLsaHeap`

Pointer to the [AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function.

### `FreeLsaHeap`

Pointer to the [FreeLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntlsa/nc-ntlsa-lsa_free_lsa_heap) function.

### `AllocateClientBuffer`

Pointer to the [AllocateClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_client_buffer) function.

### `FreeClientBuffer`

Pointer to the [FreeClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_client_buffer) function.

### `CopyToClientBuffer`

Pointer to the [CopyToClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_copy_to_client_buffer) function.

### `CopyFromClientBuffer`

Pointer to the [CopyFromClientBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_copy_from_client_buffer) function.

### `ImpersonateClient`

Pointer to the [ImpersonateClient](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa375494(v=vs.85)) function.

### `UnloadPackage`

Pointer to the [UnloadPackage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380520(v=vs.85)) function.

### `DuplicateHandle`

Pointer to the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_duplicate_handle) function.

### `SaveSupplementalCredentials`

Pointer to the **SaveSupplementalCredentials** function.

### `CreateThread`

Pointer to the [CreateThread](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_thread) function.

### `GetClientInfo`

Pointer to the [GetClientInfo](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_client_info) function.

### `RegisterNotification`

Pointer to the [RegisterNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_register_notification) function.

### `CancelNotification`

Pointer to the [CancelNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_cancel_notification) function.

### `MapBuffer`

Pointer to the [MapBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_map_buffer) function.

### `CreateToken`

Pointer to the [CreateToken](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_token) function.

### `AuditLogon`

Pointer to the [AuditLogon](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_audit_logon) function.

### `CallPackage`

Pointer to the [CallPackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_package) function.

### `FreeReturnBuffer`

Pointer to the [FreeReturnBuffer](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_lsa_heap) function.

### `GetCallInfo`

Pointer to the [GetCallInfo](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_call_info) function.

### `CallPackageEx`

Pointer to the [CallPackageEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_packageex) function.

### `CreateSharedMemory`

Pointer to the [CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory) function.

### `AllocateSharedMemory`

Pointer to the [AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory) function.

### `FreeSharedMemory`

Pointer to the [FreeSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_shared_memory) function.

### `DeleteSharedMemory`

Pointer to the [DeleteSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_shared_memory) function.

### `OpenSamUser`

Pointer to the [OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user) function.

### `GetUserCredentials`

Pointer to the **GetUserCredentials** function.

### `GetUserAuthData`

Pointer to the [GetUserAuthData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_user_auth_data) function.

### `CloseSamUser`

Pointer to the [CloseSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_close_sam_user) function.

### `ConvertAuthDataToToken`

Pointer to the [ConvertAuthDataToToken](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_convert_auth_data_to_token) function.

### `ClientCallback`

Pointer to the [ClientCallback](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_client_callback) function.

### `UpdateCredentials`

Pointer to the [UpdateCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_update_primary_credentials) function.

### `GetAuthDataForUser`

Pointer to the [GetAuthDataForUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_auth_data_for_user) function.

### `CrackSingleName`

Pointer to the [CrackSingleName](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_crack_single_name) function.

### `AuditAccountLogon`

Pointer to the [AuditAccountLogon](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_audit_account_logon) function.

### `CallPackagePassthrough`

Pointer to the [CallPackagePassthrough](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_call_package_passthrough) function.

### `CrediRead`

Pointer to the [CrediRead](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credreadfn) function.

### `CrediReadDomainCredentials`

Pointer to the [CrediReadDomainCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credreaddomaincredentialsfn) function.

### `CrediFreeCredentials`

Pointer to the [CrediFreeCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credfreecredentialsfn) function.

### `DummyFunction1`

### `DummyFunction2`

### `DummyFunction3`

### `LsaProtectMemory`

Pointer to the [LsaProtectMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_protect_memory) function.

### `LsaUnprotectMemory`

Pointer to the [LsaUnprotectMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff714510(v=vs.85)) function.

### `OpenTokenByLogonId`

Pointer to the [OpenTokenByLogonId](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_token_by_logon_id) function.

### `ExpandAuthDataForDomain`

Pointer to the [ExpandAuthDataForDomain](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_expand_auth_data_for_domain) function.

### `AllocatePrivateHeap`

Pointer to the [AllocatePrivateHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_private_heap) function.

### `FreePrivateHeap`

Pointer to the [FreePrivateHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_private_heap) function.

### `CreateTokenEx`

Pointer to the [CreateTokenEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_token_ex) function.

### `CrediWrite`

Pointer to the [CrediWrite](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-credwritefn) function.

### `CrediUnmarshalandDecodeString`

Pointer to the [CrediUnmarshalandDecodeString](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-crediunmarshalanddecodestringfn) function.

**Windows Server 2003 and Windows XP:** This function is not implemented.

### `DummyFunction4`

### `DummyFunction5`

### `DummyFunction6`

Introduced in Windows 8 and above for internal Microsoft use only.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This function is not implemented.

### `GetExtendedCallFlags`

Pointer to the **GetExtendedCallFlags** function.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This function is not implemented.

### `DuplicateTokenHandle`

Pointer to the **DuplicateTokenHandle** function.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This function is not implemented.

### `GetServiceAccountPassword`

Pointer to the **GetServiceAccountPassword** function.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This function is not implemented.

### `DummyFunction7`

Introduced in Windows 8 and above for internal Microsoft use only.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This function is not implemented.

### `AuditLogonEx`

Pointer to the **AuditLogonEx** function.

### `CheckProtectedUserByToken`

Pointer to the **CheckProtectedUserByToken** function.

### `QueryClientRequest`

Pointer to the **QueryClientRequest** function.

### `GetAppModeInfo`

Pointer to the **GetAppModeInfo** function.

### `SetAppModeInfo`

Pointer to the **SetAppModeInfo** function.