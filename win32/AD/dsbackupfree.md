# DsBackupFree function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupFree** function releases memory allocated by the Active Directory Domain Services backup and restore functions. The following functions allocate memory that must be released with the **DsBackupFree** function.

- [**DsBackupGetBackupLogs**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetbackuplogs)
- [**DsBackupGetDatabaseNames**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetdatabasenames)
- [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare)
- [**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations)

## Parameters

*pvBuffer* \[in\]

Pointer to the memory buffer to be freed.

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |

## See also

[**DsBackupGetBackupLogs**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetbackuplogs)

[**DsBackupGetDatabaseNames**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetdatabasenames)

[**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare)

[**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

