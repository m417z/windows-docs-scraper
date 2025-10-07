# DsRestoreGetDatabaseLocations function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsRestoreGetDatabaseLocations** function obtains the locations where backup files should be copied during a restore operation.

## Parameters

*hbc* \[in\]

Contains the restoration context handle obtained with the [**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare) function.

*pszDatabaseLocationList* \[out\]

Pointer to a string pointer that receives the list of database locations as UNC paths. This list receives a double null-terminated list of single null-terminated strings.

This buffer is allocated by the **DsRestoreGetDatabaseLocations** function and must be freed when it is no longer required by calling the [**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree) function.

The first character of each of the file names contains one of the [**BFT Constants**](https://learn.microsoft.com/windows/win32/ad/bft-constants) that identifies the name type. The **DsRestoreGetDatabaseLocations** function only supplies the following name types.

**BFT\_NTDS\_DATABASE**

The NTDS database file should be copied to this file. This is the file that was identified as **BFT\_NTDS\_DATABASE** when the backup was performed.

**BFT\_LOG\_DIR**

All log files are copied to this directory. The log files were identified as **BFT\_LOG** when the backup was performed.

**BFT\_CHECKPOINT\_DIR**

All patch files are copied to this directory. The patch files were identified as **BFT\_PATCH\_FILE** when the backup was performed.

*pcbSize* \[out\]

Pointer to **DWORD** value that receives the size, in bytes, of the *pszDatabaseLocationList* buffer.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**ERROR\_INVALID\_PARAMETER**

*hbc*, *pszDatabaseLocationList*, or *pcbSize* are invalid.

**ERROR\_NOT\_ENOUGH\_MEMORY**

A memory allocation failure occurred.

## Remarks

The **DsRestoreGetDatabaseLocations** function can be used to obtain the restoration directories without access to the backed up data. To do this, call [**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare) with **NULL** for the *pvExpiryToken* parameter. This causes **DsRestorePrepare** to return a restricted context handle which can only be used with the **DsRestoreGetDatabaseLocations** function.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsRestoreGetDatabaseLocationsW** (Unicode) and **DsRestoreGetDatabaseLocationsA** (ANSI)<br> |

## See also

[**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare)

[**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

[Restoring Active Directory](https://learn.microsoft.com/windows/win32/ad/restoring-an-active-directory-server)

