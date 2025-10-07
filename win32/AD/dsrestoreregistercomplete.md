# DsRestoreRegisterComplete function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsRestoreRegisterComplete** function is called to unlock an Active Directory server after a restore operation is complete. This function is counterpart to the [**DsRestoreRegister**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregister) function.

## Parameters

*hbc* \[in\]

Contains the restoration context handle obtained with the [**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare) function.

*hrRestoreState* \[in\]

Contains the final status of the restore operation. This parameter should contain **S\_OK** if the restore operation was successful or an error code otherwise.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

## Remarks

Before you restart the domain controller, call this function to provide the status of the restore operation. If the status is not successful, the directory service will not start until a valid database has been restored. This function completes the restore operation and allows Active Directory Domain Services to start.

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

[**DsRestoreRegister**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregister)

[**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare)

[**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity)

[Restoring an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/restoring-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

