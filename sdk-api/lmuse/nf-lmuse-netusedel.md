# NetUseDel function

## Description

The
**NetUseDel** function ends a connection to a shared resource.

You can also use the
[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a) function to terminate a network connection.

## Parameters

### `UncServerName` [in]

The UNC name of the computer on which to execute this function. If this is parameter is **NULL**, then the local computer is used.

If the *UncServerName* parameter specified is a remote computer, then the remote computer must support remote RPC calls using the legacy Remote Access Protocol mechanism.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `UseName` [in]

A pointer to a string that specifies the path of the connection to delete.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `ForceLevelFlags` [in]

The level of force to use in deleting the connection.

 This parameter can be one of the following values defined in the *lmuseflg.h* header file.

| Value | Meaning |
| --- | --- |
| **USE_NOFORCE** | Fail the disconnection if open files exist on the connection. |
| **USE_FORCE** | Do not fail the disconnection if open files exist on the connection. |
| **USE_LOTS_OF_FORCE** | Close any open files and delete the connection. |

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **NetUseDel** function applies only to the Server Message Block (LAN Manager Workstation) client. The **NetUseDel** function does not support Distributed File System (DFS) shares or other network file systems. To terminate a connection to a share using a different network provider (WebDAV or a DFS share, for example), use the [WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a) function.

No special group membership is required to call the
**NetUseDel** function. This function cannot be executed on a remote server except in cases of downlevel compatibility.

## See also

[NetUseAdd](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseadd)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Use Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/use-functions)

[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a)