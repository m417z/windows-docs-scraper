# NetFileClose function

## Description

Forces a resource to close. This function can be used when an error prevents closure by any other means. You should use
**NetFileClose** with caution because it does not write data cached on the client system to the file before closing the file.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `fileid` [in]

Specifies the file identifier of the opened resource instance to close.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_FILE_NOT_FOUND** | The file was not found. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetFileClose** function.

## See also

[NetFile
Functions](https://learn.microsoft.com/windows/desktop/NetShare/netfile-functions)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)