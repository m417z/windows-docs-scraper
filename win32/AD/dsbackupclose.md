# DsBackupClose function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupClose** function closes a backup file opened with the [**DsBackupOpenFile**](https://learn.microsoft.com/windows/win32/ad/dsbackupopenfile) function. For each backup handle, only one file can be opened at a time, so this function closes the currently open file.

## Parameters

*hbc* \[in\]

Contains the backup context handle obtained with the [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare) function.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists other possible error codes.

**ERROR\_INVALID\_PARAMETER**

*hbc* is not valid.

**hrInvalidHandle**

No file is currently open.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |

## See also

[**DsBackupOpenFile**](https://learn.microsoft.com/windows/win32/ad/dsbackupopenfile)

[**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

