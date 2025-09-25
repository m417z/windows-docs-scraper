# LSA_DELETE_CREDENTIAL callback function

## Description

Deletes an existing credential.

This function deletes the first credential it finds with a matching logon session ID, authentication package ID, and primary lookup key value. If there are multiple matching credentials, only one of them is deleted.

This function is not used by newer authentication packages, such as Kerberos.

## Parameters

### `LogonId` [in]

Pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure containing the session ID of the logon session from which the credential is to be deleted.

### `AuthenticationPackage` [in]

Authentication package ID of the calling authentication package received in the
[LsaApInitializePackage](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_initialize_package) call during DLL initialization.

### `PrimaryKeyValue` [in]

Contains the primary lookup key of the credential to be deleted.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **ERROR_GEN_FAILURE** | No matching credential could be found. |
| **STATUS_NO_SUCH_LOGON_SESSION** | The specified logon session could not be found. |

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)