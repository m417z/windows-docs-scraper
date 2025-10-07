# DsBackupGetDatabaseNames function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupGetDatabaseNames** function obtains the list of database files to be backed up for the given backup context.

## Parameters

*hbc* \[in\]

Contains the backup context handle obtained with the [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare) function.

*pszAttachmentInfo* \[out\]

Pointer to a string pointer that receives the list of database file names as UNC paths. This value must be initialized to **NULL** prior to calling **DsBackupGetDatabaseNames**.

This list receives a double null-terminated list of single null-terminated strings.

This buffer is allocated by the **DsBackupGetDatabaseNames** function and must be freed when it is no longer required by calling the [**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree) function.

The first character of each file name contains one of the [**BFT Constants**](https://learn.microsoft.com/windows/win32/ad/bft-constants) that identifies the type of name. The [**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations) function only supplies the following types of names.

**BFT\_NTDS\_DATABASE**

The file is an NTDS database file. This file should be copied to the file identified as **BFT\_NTDS\_DATABASE** when the data is restored.

**BFT\_LOG**

The file is a log file. All log files are copied to the directory identified as **BFT\_LOG\_DIR** when the data is restored.

**BFT\_PATCH\_FILE**

The file is a patch file. All patch files are copied to the directory identified as **BFT\_CHECKPOINT\_DIR** when the data is restored.

*pcbSize* \[out\]

Pointer to **DWORD** value that receives the size, in bytes, of the *pszAttachmentInfo* buffer.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists other possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**ERROR\_INVALID\_PARAMETER**

*hbc*, *pszAttachmentInfo*, or *pcbSize* are invalid.

**ERROR\_NOT\_ENOUGH\_MEMORY**

A memory allocation failure occurred.

## Remarks

The **DsBackupGetDatabaseNames** function provides a list of the database files necessary for a backup. A full backup consists of the database files and the log files provided by the [**DsBackupGetBackupLogs**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetbackuplogs) function. Incremental backups of Active Directory servers are not supported.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsBackupGetDatabaseNamesW** (Unicode) and **DsBackupGetDatabaseNamesA** (ANSI)<br> |

## See also

[**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare)

[**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree)

[**DsBackupGetBackupLogs**](https://learn.microsoft.com/windows/win32/ad/dsbackupgetbackuplogs)

[**BFT Constants**](https://learn.microsoft.com/windows/win32/ad/bft-constants)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

