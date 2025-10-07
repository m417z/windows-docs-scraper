# DsRestoreRegister function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsRestoreRegister** function registers a restore operation.This function interlocks all subsequent restore operations and prevents the restore target from starting until the [**DsRestoreRegisterComplete**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregistercomplete) function is called.

## Parameters

*hbc* \[in\]

Contains the restoration context handle obtained with the [**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare) function.

*szCheckPointFilePath* \[in\]

Pointer to a null-terminated string that contains the path to the checkpoint file. This path is provided by the [**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations) function and has a **BFT** value of **BFT\_CHECKPOINT\_DIR**. Typically this is the same as the system database path. This path is required for proper backup restore function. This parameter cannot be **NULL**. Passing **NULL** in this parameter will cause an error during the restore process.

*szLogPath* \[in\]

Pointer to a null-terminated string that contains the path where the log files will be restored. This path is provided by the [**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations) function and has a **BFT** value of **BFT\_LOG\_DIR**. If the path points to an empty directory, new log files are created there. This parameter cannot be **NULL**.

*rgrstmap* \[in\]

An array of [**EDB\_RSTMAP**](https://learn.microsoft.com/windows/win32/ad/edb-rstmap) structures that contains the old and new paths for each database. There is one structure for each database. For the directory, there is a structure for the system database and another structure for the directory database. The order of the elements in the array does not matter. The *crstmap* parameter contains the number of elements in the array.

*crstmap* \[in\]

Contains the number of elements in the *rgrstmap* array.

*szBackupLogPath* \[in\]

Pointer to a null-terminated string that contains the path where the backed up log files currently reside. This parameter cannot be **NULL**.

*genLow* \[in\]

Contains the lowest log number to restore in this restore session. This is a hexadecimal number in the range from 0x00000 to 0xFFFFF.

*genHigh* \[in\]

Contains the highest log number to restore in this restore session. This is a hexadecimal number in the range from 0x00000 to 0xFFFFF.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**ERROR\_INVALID\_PARAMETER**

One or more parameters are invalid.

**hrMissingExpiryToken**

The expiry token supplied to [**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare) was invalid. This value is defined in Ntdsbmsg.h.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsRestoreRegisterW** (Unicode) and **DsRestoreRegisterA** (ANSI)<br> |

## See also

[**DsRestoreRegisterComplete**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregistercomplete)

[**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare)

[**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations)

[**DsRestoreEnd**](https://learn.microsoft.com/windows/win32/ad/dsrestoreend)

[**EDB\_RSTMAP**](https://learn.microsoft.com/windows/win32/ad/edb-rstmap)

[Restoring Active Directory](https://learn.microsoft.com/windows/win32/ad/restoring-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

