# LSA_DELETE_LOGON_SESSION callback function

## Description

Cleans up any logon sessions created while determining whether a user's authentication information is legitimate.

If the authentication fails, the authentication package should delete all related logon sessions.

## Parameters

### `LogonId` [in]

Pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure containing the session ID of logon session to delete.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_BAD_LOGON_SESSION_STATE** | The specified logon session has a reference count value that prevents it from being deleted. This is a serious problem, caused by both the operating system and authentication package believing they have authority over the logon session. |
| **STATUS_NO_SUCH_LOGON_SESSION** | The specified logon session could not be found. |

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## Remarks

Because logon sessions use up memory in the kernel, any unused or discarded logon sessions should be deleted. However, logon sessions should not be deleted after a logon ID for the session has been returned to the LSA. After the LSA has been given a logon ID (for example, as a result of a
[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user) call), the LSA assumes it is responsible for the logon session and will delete it when the operating system no longer needs it. At this time, the LSA calls
[LsaApLogonTerminated](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_terminated) to notify the authentication package that the session has been deleted.

In contrast, authentication packages are not notified when a logon session is deleted with **DeleteLogonSession**.

## See also

[CreateLogonSession](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_logon_session)

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)