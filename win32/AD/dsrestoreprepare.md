# DsRestorePrepare function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsRestorePrepare** function connects to the specified directory server and prepares it for the restore operation.

## Parameters

*szServerName* \[in\]

Pointer to a null-terminated string that contains the name of the server to restore. Preceding backslashes are optional. The server must be the same computer that this function is called from. The server name cannot contain any underscore (\_) characters. An example of a server name is "\\\\server1".

*rtFlag* \[in\]

Specifies the type of restoration to perform. This can be zero or one of the following values.

**RESTORE\_TYPE\_CATCHUP**

Default. The restored version is reconciled through the standard reconciliation logic so that the restored DIT can synchronize with other enterprise server computers.

**RESTORE\_TYPE\_AUTHORATATIVE**

Not Supported.

**RESTORE\_TYPE\_ONLINE**

Not Supported. Restoration is performed when NTDS is online.

*pvExpiryToken* \[in\]

Pointer to the expiry token associated with the backup being restored. This token was obtained from the [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare) function when the directory was backed up.

If this parameter is **NULL**, the handle returned in *phbc* can only be used to obtain the restoration directories with the [**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations) function. The handle cannot be used for any other restoration functions.

*cbExpiryTokenSize* \[in\]

Contains the size, in bytes, of the expiry token in *pvExpiryToken*.

*phbc* \[out\]

Pointer to an **HBC** value that receives the handle for the restore. This handle is used when calling other Directory Service restore functions, such as [**DsBackupOpenFile**](https://learn.microsoft.com/windows/win32/ad/dsbackupopenfile) and [**DsRestoreEnd**](https://learn.microsoft.com/windows/win32/ad/dsrestoreend).

## Return value

If successful, returns a standard **HRESULT** codes; otherwise, a failure code is returned.

## Remarks

The **DsRestorePrepare** function requires that the caller is a member of the Administrators group on the server.

**DsRestorePrepare** may be used with or without a token provided. If the token is provided, it is checked for expiration, and all operations are allowed on the context returned. If the token is not provided, the context returned is restricted, and may be used only for the [**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations) function. It may not be used for the [**DsRestoreRegister**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregister) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsRestorePrepareW** (Unicode) and **DsRestorePrepareA** (ANSI)<br> |

## See also

[Restoring an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/restoring-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

[**DsRestoreGetDatabaseLocations**](https://learn.microsoft.com/windows/win32/ad/dsrestoregetdatabaselocations)

[**DsRestoreRegister**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregister)

[**DsRestoreRegisterComplete**](https://learn.microsoft.com/windows/win32/ad/dsrestoreregistercomplete)

[**DsRestoreEnd**](https://learn.microsoft.com/windows/win32/ad/dsrestoreend)

