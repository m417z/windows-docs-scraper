# NetUseEnum function

## Description

The
**NetUseEnum** function lists all current connections between the local computer and resources on remote servers.

You can also use the
[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma) and the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea) functions to enumerate network resources or connections.

## Parameters

### `UncServerName` [in]

The UNC name of the computer on which to execute this function. If this is parameter is **NULL**, then the local computer is used. If the *UncServerName* parameter specified is a remote computer, then the remote computer must support remote RPC calls using the legacy Remote Access Protocol mechanism.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `LevelFlags` [in]

The information level of the data requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Specifies a local device name and the share name of a remote resource. The *BufPtr* parameter points to an array of [USE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_0) structures. |
| 1 | Specifies information about the connection between a local device and a shared resource, including connection status and type. The *BufPtr* parameter points to an array of [USE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_1) structures. |
| 2 | Specifies information about the connection between a local device and a shared resource. Information includes the connection status, connection type, user name, and domain name. The *BufPtr* parameter points to an array of [USE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_2) structures. |

### `BufPtr` [out]

A pointer to the buffer that receives the information structures. The format of this data depends on the value of the *Level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function when the information is no longer needed. Note that you must free the buffer even if the function fails with **ERROR_MORE_DATA**.

### `PreferedMaximumSize` [in]

The preferred maximum length, in bytes, of the data to return. If **MAX_PREFERRED_LENGTH** is specified, the function allocates the amount of memory required for the data. If another value is specified in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns **ERROR_MORE_DATA**. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `EntriesRead` [out]

A pointer to a value that receives the count of elements actually enumerated.

### `TotalEntries` [out]

A pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `ResumeHandle` [in, out]

A pointer to a value that contains a resume handle which is used to continue the search. The handle should be zero on the first call and left unchanged for subsequent calls. If *ResumeHandle* is **NULL**, then no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *BufPtr* or *entriesread* parameters. |
| **ERROR_MORE_DATA** | There is more data to return. This error is returned if the buffer size is insufficient to hold all entries. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the *UncServerName* parameter was not **NULL** and the remote server does not support remote RPC calls using the legacy Remote Access Protocol mechanism. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

No special group membership is required to call the
**NetUseEnum** function. This function cannot be executed on a remote server except in cases of downlevel compatibility using the legacy Remote Access Protocol.

To retrieve information about one network connection, you can call the
[NetUseGetInfo](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netusegetinfo) function.

This function applies only to the Server Message Block (LAN Manager Workstation) client. The **NetUseEnum** function does not support Distributed File System (DFS) shares. To enumerate shares using a different network provider (WebDAV or a DFS share, for example), use the [WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma), [WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea), and [WNetCloseEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcloseenum) functions.

## See also

[NetUseGetInfo](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netusegetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_0)

[USE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_1)

[USE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmuse/ns-lmuse-use_info_2)

[Use Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/use-functions)

[WNetCloseEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcloseenum)

[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea)

[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma)