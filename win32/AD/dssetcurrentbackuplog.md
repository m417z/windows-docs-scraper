# DsSetCurrentBackupLog function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsSetCurrentBackupLog** function sets the current backup log number after a successful restore. Because Active Directory Domain Services only support circular logging, this function is not normally used.

## Parameters

*szServerName* \[in\]

Pointer to a null-terminated string that contains the name of the server to set the backup log number for. Preceding backslashes are optional. The server must be the same computer that this function is called from. The server name cannot contain any underscore (\_) characters. An example of a server name is "\\\\server1".

*dwCurrentLog* \[in\]

Contains the backup log number to set.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. The following list lists possible error codes.

**ERROR\_INVALID\_PARAMETER**

One or more parameters are invalid.

**ERROR\_NOT\_ENOUGH\_MEMORY**

A memory allocation failure occurred.

## Remarks

It is not normally required to call the **DsSetCurrentBackupLog** function. The backup functions automatically determine and set the last log number backed up. Use **DsSetCurrentBackupLog** to prevent another incremental backup from succeeding until a full backup is performed.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsSetCurrentBackupLogW** (Unicode) and **DsSetCurrentBackupLogA** (ANSI)<br> |

## See also

[Backing Up and Restoring an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-and-restoring-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

