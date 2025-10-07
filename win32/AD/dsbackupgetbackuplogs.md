# DsBackupGetBackupLogs function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupGetBackupLogs** function obtains the list of log files that must be backed up for the given backup context.

## Parameters

*hbc* \[in\]

Contains the backup context handle obtained with the [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare) function.

*pszBackupLogFiles* \[out\]

Pointer to a string pointer that receives the list of log file names as UNC paths. Initialize this value to **NULL** before calling **DsBackupGetBackupLogs**.

This list receives a double null-terminated list of single null-terminated strings.

This buffer is allocated by the **DsBackupGetBackupLogs** function and must be freed when no longer required by calling the [**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree) function.

The first character of each of the file names contains one of the [**BFT Constants**](https://learn.microsoft.com/windows/win32/ad/bft-constants) that identifies the type of name.

*pcbSize* \[out\]

Pointer to **DWORD** value that receives the size, in bytes, of the *pszBackupLogFiles* buffer.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists other possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**ERROR\_INVALID\_PARAMETER**

*hbc*, *pszBackupLogFiles*, or *pcbSize* is invalid.

**ERROR\_NOT\_ENOUGH\_MEMORY**

A memory allocation failure occurred.

## Remarks

The **DsBackupGetBackupLogs** function provides a list of the log files necessary for a backup. A full backup consists of the database files provided by the [**DsBackupGetDatabaseNames**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetdatabasenames) function and the log files. Incremental backups of Active Directory servers are not supported.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsBackupGetBackupLogsW** (Unicode) and **DsBackupGetBackupLogsA** (ANSI)<br> |

## See also

[**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree)

[**DsBackupGetDatabaseNames**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetdatabasenames)

[**BFT Constants**](https://learn.microsoft.com/windows/win32/ad/bft-constants)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

