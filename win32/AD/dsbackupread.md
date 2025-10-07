# DsBackupRead function

\[This function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Beginning with Windows Vista, use [Volume Shadow Copy Service (VSS)](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead.\]

The **DsBackupRead** function reads a block of data from the current open file, into a buffer. The client application is expected to call this function repeatedly until the entire backup file has been received. The [**DsBackupOpenFile**](https://learn.microsoft.com/windows/win32/ad/dsbackupopenfile) function provides the entire size of the backup file.

## Parameters

*hbc* \[in\]

Contains the backup context handle obtained with the [**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare) function.

*pvBuffer* \[in\]

Pointer to a buffer that receives the data. This buffer must be at least *cbBuffer* bytes in size.

*cbBuffer* \[in\]

Contains the size, in bytes, of the buffer at *pvBuffer*. This value must be a multiple of 8192 and must be greater than or equal to 24576.

*pcbRead* \[out\]

Pointer to a **DWORD** value that receives the actual number of bytes read. This may be less than the number of bytes requested because some transports fragment the buffer being transmitted instead of filling the entire buffer with data.

## Return value

Returns **S\_OK** if the function is successful or a Win32 or RPC error code otherwise. Possible error codes include the following.

**ERROR\_INVALID\_PARAMETER**

One or more parameters are not valid.

**ERROR\_HANDLE\_EOF**

The end of the backup file was reached.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | Ntdsbcli.h |
| Library<br> | Ntdsbcli.lib |
| DLL<br> | Ntdsbcli.dll |

## See also

[**DsBackupOpenFile**](https://learn.microsoft.com/windows/win32/ad/dsbackupopenfile)

[**DsBackupPrepare**](https://learn.microsoft.com/windows/win32/ad/dsbackupprepare)

[**DsBackupFree**](https://learn.microsoft.com/windows/win32/ad/dsbackupfree)

[Backing Up an Active Directory Server](https://learn.microsoft.com/windows/win32/ad/backing-up-an-active-directory-server)

[Directory Backup Functions](https://learn.microsoft.com/windows/win32/ad/directory-backup-functions)

