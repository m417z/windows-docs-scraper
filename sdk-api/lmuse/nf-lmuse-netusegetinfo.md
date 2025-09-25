# NetUseGetInfo function

## Description

The
**NetUseGetInfo** function retrieves information about a connection to a shared resource.

You can also use the
[WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona) function to retrieve the name of a network resource associated with a local device.

## Parameters

### `UncServerName` [in]

The UNC name of computer on which to execute this function. If this is parameter is **NULL**, then the local computer is used. If the *UncServerName* parameter specified is a remote computer, then the remote computer must support remote RPC calls using the legacy Remote Access Protocol mechanism.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `UseName` [in]

A pointer to a string that specifies the name of the connection for which to return information.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `LevelFlags` [in]

The information level of the data requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Specifies a local device name and the share name of a remote resource. The *BufPtr* parameter is a pointer to a [USE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_0) structure. |
| 1 | Specifies information about the connection between a local device and a shared resource, including connection status and type. The *BufPtr* parameter is a pointer to a [USE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_1) structure. |
| 2 | Specifies information about the connection between a local device and a shared resource. Information includes the connection status, connection type, user name, and domain name. The *BufPtr* parameter is a pointer to a [USE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_2) structure. |

### `bufptr` [out]

A pointer to the buffer that receives the data. The format of this data depends on the value of the *Level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required to call the
**NetUseGetInfo** function. This function cannot be executed on a remote server except in cases of downlevel compatibility.

To list all current connections between the local computer and resources on remote servers, you can call the
[NetUseEnum](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseenum) function.

This function applies only to the Server Message Block (LAN Manager Workstation) client. The **NetUseGetInfo** function does not support Distributed File System (DFS) shares. To retrieve information for a share using a different network provider (WebDAV or a DFS share, for example), use the [WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona) function.

## See also

[NetUseEnum](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_0)

[USE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_1)

[USE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_2)

[Use Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/use-functions)

[WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona)