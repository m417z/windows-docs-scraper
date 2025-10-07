# DsBackupOpenFile function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupOpenFile** function opens the specified file and performs the client and server operations necessary to prepare the file for backup.

## Parameters

*hbc* \[in\]

Contains the backup context handle obtained with the [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare) function.

*szAttachmentName* \[in\]

Pointer to a null-terminated string that specifies the name of the backup file to open.

*cbReadHintSize* \[in\]

Contains the possible size, in bytes, of the buffer passed as the *pvBuffer* argument in the [**DsBackupRead**](https://learn.microsoft.com/windows/win32/ad/dsbackupread) function. The backup functions use this value as a hint to optimize the network traffic. This value must be a multiple of 8192 and must be greater than or equal to 24576.

*pliFileSize* \[out\]

Pointer to a **LARGE\_INTEGER** value that receives the size, in bytes, of the backup file opened.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists other possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**ERROR\_INVALID\_PARAMETER**

*hbc*, *szAttachmentName*, or *pliFileSize* are invalid.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsBackupOpenFileW** (Unicode) and **DsBackupOpenFileA** (ANSI)<br> |

## See also

[**DsBackupRead**](https://learn.microsoft.com/windows/win32/ad/dsbackupread)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

