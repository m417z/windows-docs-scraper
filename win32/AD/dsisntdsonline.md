# DsIsNTDSOnline function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsIsNTDSOnline** function determines if Active Directory Domain Services are online on the specified server.

## Parameters

*szServerName* `[in]`

Pointer to a null-terminated string that contains the name of the server to test. Preceding backslashes are optional. The server must be the same computer that this function is called from. The server name cannot contain any underscore (\_) characters. An example of a server name is "\\\\server1".

*pfNTDSOnline* `[out]`

Pointer to **BOOL** value that receives the result. Receives **TRUE** if the directory service is online or **FALSE** if the directory service is offline.

## Return value

Returns **S\_OK** if the function is successful or an error code otherwise. The following list lists possible error codes.

**ERROR\_ACCESS\_DENIED**

The caller does not have the proper access privileges to call this function. The [**DsSetAuthIdentity**](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity) function can be used to set the credentials to use for the backup and restore functions.

**hrCouldNotConnect**

The server in *szServerName* cannot be found, is not a domain controller, or *szServerName* is not formatted correctly. This value is defined in Ntdsbmsg.h.

**RPC\_S\_INVALID\_BINDING**

The **DsIsNTDSOnline** function is being called remotely or the server in *szServerName* is not a domain controller.

## Remarks

Call this function before calling any of the directory backup or restore functions. The directory must be online in order to perform a backup. The directory must by offline to perform a restore.

This function can only be called from a domain controller that is also the target server specified in *szServerName*. This function cannot be called remotely.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client | Windows Vista |
| Minimum supported server | Windows Server 2008 |
| Header | `Ntdsbcli.h` |
| Library | `Ntdsbcli.lib` |
| DLL | `Ntdsbcli.dll` |
| Unicode and ANSI names | **DsIsNTDSOnlineW** (Unicode) and **DsIsNTDSOnlineA** (ANSI) |

## See also

[DsSetAuthIdentity](https://learn.microsoft.com/windows/win32/ad/dssetauthidentity)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

[Backing Up and Restoring an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-and-restoring-an-active-directory-server)