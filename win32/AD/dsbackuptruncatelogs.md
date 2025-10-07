# DsBackupTruncateLogs function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupTruncateLogs** function truncates the previously read backup logs.

## Parameters

*hbc* \[in\]

Contains the backup context handle obtained with the [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare) function.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists other possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**ERROR\_INVALID\_PARAMETER**

*hbc* is invalid.

## Remarks

Use the **DsBackupTruncateLogs** function when a full or incremental backup has completed successfully.

> [!Caution]
> If this function is called after a differential backup, all of the incremental backup information will be lost.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |

## See also

[**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare)

[**DsBackupGetBackupLogs**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetbackuplogs)

[**DsSetCurrentBackupLog**](https://learn.microsoft.com/windows/win32/ad/dssetcurrentbackuplog)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

