# DsSetAuthIdentity function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsSetAuthIdentity** function sets the security context under which the directory backup APIs are called.

## Parameters

*szUserName* \[in\]

The null-terminated string that specifies the user name.

*szDomainName* \[in\]

The null-terminated string that specifies the name of the domain that the user belongs to.

*szPassword* \[in\]

The null-terminated string that specifies the password of the user in the specified domain.

## Return value

If successful, returns a standard **HRESULT** success codes; otherwise, a failure code is returned.

## Remarks

If **DsSetAuthIdentity** is not called, security context of the current process is assumed.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |
| Unicode and ANSI names<br> | **DsSetAuthIdentityW** (Unicode) and **DsSetAuthIdentityA** (ANSI)<br> |

## See also

[Backing Up and Restoring an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-and-restoring-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

