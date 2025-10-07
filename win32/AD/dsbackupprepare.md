# DsBackupPrepare function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupPrepare** function prepares the directory on the specified server for the online backup and returns a backup context handle used in subsequent calls to other backup functions.

## Parameters

*szBackupServer* \[in\]

Pointer to a null-terminated string that contains the name of the server to backup. Preceding backslashes are optional. The server must be the same computer that this function is called from. The server name cannot contain an underscore (\_) character. An example of a server name is "\\\\server1".

*grbit* \[in\]

Determines if the log files will be backed up. This value should always be 0 because incremental backups are not supported.

*btBackupType* \[in\]

Specifies the type of backup. This can be one of the following values.

**BACKUP\_TYPE\_FULL**

Specifies a full backup. The complete directory (DIT, log files, and update files) are backed up. All data is backed up and transaction log files are truncated. Only full backups are supported.

**BACKUP\_TYPE\_LOGS\_ONLY**

This value is not supported. Specifies that only the database logs, and not the database itself, will be backed up. This is normally used when performing a differential or incremental backup.

**BACKUP\_TYPE\_INCREMENTAL**

This value is not supported. **DsBackupPrepare** returns **ERROR\_INVALID\_PARAMETER**.

*ppvExpiryToken* \[out\]

Pointer to a **PVOID** value that receives a pointer to an expiry token associated with this backup. *pcbExpiryTokenSize* receives the size, in bytes, of this data. The caller must save the contents of this token with the backup because the token must be passed to [**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare) when attempting to restore data. After the token has been stored and is no longer required, the caller should free the allocated memory using [**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree).

*pcbExpiryTokenSize* \[out\]

Pointer to a **DWORD** value that receives the size, in bytes, of the token in *ppvExpiryToken*.

*phbc* \[out\]

Pointer to an **HBC** value that receives the handle for the backup. This handle is used when calling other Directory Service backup functions, such as [**DsBackupOpenFile**](https://learn.microsoft.com/windows/win32/ad/dsbackupopenfile) and [**DsBackupEnd**](https://learn.microsoft.com/windows/win32/ad/dsbackupend).

## Return value

Returns **S\_OK** if the function is successful or an error code otherwise. The following list lists other possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**ERROR\_INVALID\_PARAMETER**

*szBackupServer* or *phbcBackupContext* are not valid.

**ERROR\_NOT\_ENOUGH\_MEMORY**

A memory allocation failure occurred.

**hrCouldNotConnect**

The server in *szBackupServer* could not be found, is not a domain controller or *szBackupServer* is not formatted correctly. This value is defined in ntdsbmsg.h.

**hrInvalidParam**

*ppvExpiryToken* and/or *pcbExpiryTokenSize* are invalid. This value is defined in Ntdsbmsg.h.

**RPC\_S\_INVALID\_BINDING**

The function is called remotely or the server in *szServerName* is not a domain controller.

## Remarks

This function requires that the caller has the **SE\_BACKUP\_NAME** privilege. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to change the security context under which this function is called.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsBackupPrepareW** (Unicode) and **DsBackupPrepareA** (ANSI)<br> |

## See also

[**DsRestorePrepare**](https://learn.microsoft.com/windows/win32/ad/dsrestoreprepare)

[**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree)

[**DsBackupOpenFile**](https://learn.microsoft.com/windows/win32/ad/dsbackupopenfile)

[**DsBackupEnd**](https://learn.microsoft.com/windows/win32/ad/dsbackupend)

[**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

