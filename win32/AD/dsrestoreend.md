# DsRestoreEnd function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsRestoreEnd** function is called to terminate a restore operation.

## Parameters

*hbc* \[in\]

Contains the restoration context handle obtained with the [**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare) function.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists possible error codes.

**ERROR\_INVALID\_PARAMETER**

*hbc* is not valid.

## Remarks

The **DsRestoreEnd** function closes outstanding binding handles and performs a cleanup operation after a restore attempt.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | None supported<br> |
| End of server support<br> | None supported<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |

## See also

[**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare)

[Restoring an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/restoring-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

