# LSA_CREATE_LOGON_SESSION callback function

## Description

Creates logon sessions.

The logon session is identified by a unique logon ID (
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)) assigned to the logon session.

## Parameters

### `LogonId` [in]

Pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure to be assigned to the new logon session. An authentication package calls
[AllocateLocallyUniqueId](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocatelocallyuniqueid) in order to generate this ID.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be the following value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_LOGON_SESSION_COLLISION** | The specified logon ID is already in use by another logon session. |

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

If an authentication package creates extraneous logon sessions while determining whether to authenticate the user, it should delete them by calling
[DeleteLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_logon_session). If the authentication fails, the authentication package should delete all related logon sessions.

Because logon sessions use memory in the kernel, it is important to delete any unused or discarded logon sessions.

## See also

[DeleteLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_logon_session)

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)