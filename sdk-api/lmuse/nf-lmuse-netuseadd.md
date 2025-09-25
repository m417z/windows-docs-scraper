# NetUseAdd function

## Description

The
**NetUseAdd** function establishes a connection between the local computer and a remote server. You can specify a local drive letter or a printer device to connect. If you do not specify a local drive letter or printer device, the function authenticates the client with the server for future connections.

## Parameters

### `servername` [in]

The UNC name of the computer on which to execute this function. If this parameter is **NULL**, then the local computer is used. If the *UncServerName* parameter specified is a remote computer, then the remote computer must support remote RPC calls using the legacy Remote Access Protocol mechanism.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `LevelFlags` [in]

A value that specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **1** | Specifies information about the connection between a local device and a shared resource. Information includes the connection status and type. The *Buf* parameter is a pointer to a [USE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_1) structure. |
| **2** | Specifies information about the connection between a local device and a shared resource. Information includes the connection status and type, and a user name and domain name. The *Buf* parameter is a pointer to a [USE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_2) structure. |

### `buf` [in]

A pointer to the buffer that specifies the data. The format of this data depends on the value of the *Level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

A pointer to a value that receives the index of the first member of the information structure in error when the ERROR_INVALID_PARAMETER error is returned. If this parameter is **NULL**, the index is not returned on error. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

You can also use the
[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) and [WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a) functions to redirect a local device to a network resource.

No special group membership is required to call the
**NetUseAdd** function. This function cannot be executed on a remote server except in cases of downlevel compatibility.

This function applies only to the Server Message Block (LAN Manager Workstation) client. The **NetUseAdd** function does not support Distributed File System (DFS) shares. To add a share using a different network provider (WebDAV or a DFS share, for example), use the [WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) or [WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a) function.

If the
**NetUseAdd** function returns ERROR_INVALID_PARAMETER, you can use the *ParmError* parameter to indicate the first member of the information structure that is invalid. (The information structure begins with USE_INFO_ and its format is specified by the *Level* parameter.) The following table lists the values that can be returned in the *ParmError* parameter and the corresponding structure member that is in error. (The prefix ui***_ indicates that the member can begin with multiple prefixes, for example, ui1_ or ui2_.)

| Constant | Value | Member |
| --- | --- | --- |
| USE_LOCAL_PARMNUM | 1 | ui***_local |
| USE_REMOTE_PARMNUM | 2 | ui***_remote |
| USE_PASSWORD_PARMNUM | 3 | ui***_password |
| USE_ASGTYPE_PARMNUM | 4 | ui***_asg_type |
| USE_USERNAME_PARMNUM | 5 | ui***_username |
| USE_DOMAINNAME_PARMNUM | 6 | ui***_domainname |

## See also

[NetUseDel](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netusedel)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_1)

[USE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_2)

[Use Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/use-functions)

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a)