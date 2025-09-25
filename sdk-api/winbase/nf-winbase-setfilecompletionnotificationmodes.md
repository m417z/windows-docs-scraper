# SetFileCompletionNotificationModes function

## Description

 Sets the notification modes for a file handle, allowing you to specify how completion notifications
work for the specified file.

## Parameters

### `FileHandle` [in]

A handle to the file.

### `Flags` [in]

The modes to be set. One or more modes can be set at the same time; however, after a mode has been set for
a file handle, it cannot be removed.

| Value | Meaning |
| --- | --- |
| **FILE_SKIP_COMPLETION_PORT_ON_SUCCESS**<br><br>0x1 | If the following three conditions are true, the I/O Manager does not queue a completion entry to the port, when it would ordinarily do so. The conditions are:<br><br>* A completion port is associated with the file handle.<br>* The file is opened for asynchronous I/O.<br>* A request returns success immediately without returning   **ERROR_PENDING**.<br><br>When the *FileHandle* parameter is a socket, this mode is only compatible with Layered Service Providers (LSP) that return Installable File Systems (IFS) handles. To detect whether a non-IFS LSP is installed, use the [WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function and examine the **dwServiceFlag1** member in each returned [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. If the **XP1_IFS_HANDLES** (0x20000) bit is cleared then the specified LSP is not an IFS LSP. Vendors that have non-IFS LSPs are encouraged to migrate to the [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page) (WFP). |
| **FILE_SKIP_SET_EVENT_ON_HANDLE**<br><br>0x2 | The I/O Manager does not set the event for the file object if a request returns with a success code, or the error returned is **ERROR_PENDING** and the function that is called is not a synchronous function.<br><br>If an explicit event is provided for the request, it is still signaled. |

## Return value

Returns nonzero if successful or zero otherwise.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define the **_WIN32_WINNT** macro
as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)