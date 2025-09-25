# WSAProviderConfigChange function

## Description

The
**WSAProviderConfigChange** function notifies the application when the provider configuration is changed.

## Parameters

### `lpNotificationHandle` [in, out]

Pointer to notification handle. If the notification handle is set to **NULL** (the handle value not the pointer itself), this function returns a notification handle in the location pointed to by *lpNotificationHandle*.

### `lpOverlapped` [in]

Pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

Pointer to the completion routine called when the provider change notification is received.

## Return value

If no error occurs the
**WSAProviderConfigChange** returns 0. Otherwise, a value of SOCKET_ERROR is returned and a specific error code may be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). The error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) indicates that the overlapped operation has been successfully initiated and that completion (and thus change event) will be indicated at a later time.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Not enough free memory available to complete the operation. |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Value pointed by *lpNotificationHandle* parameter is not a valid notification handle. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Current operating system environment does not support provider installation or removal without restart. |

## Remarks

The
**WSAProviderConfigChange** function notifies the application of provider (both transport and namespace) installation or removal in Windows operating environments that support such configuration change without requiring a restart. When called for the first time (*lpNotificationHandle* parameter points to **NULL** handle), this function completes immediately and returns notification handle in the location pointed by *lpNotificationHandle* that can be used in subsequent calls to receive notifications of provider installation and removal. The second and any subsequent calls only complete when provider information changes since the time the call was made It is expected (but not required) that the application uses overlapped I/O on second and subsequent calls to
**WSAProviderConfigChange**, in which case the call will return immediately and application will be notified of provider configuration changes using the completion mechanism chosen through specified overlapped completion parameters.

Notification handle returned by
**WSAProviderConfigChange** is like any regular operating system handle that should be closed (when no longer needed) using Windows
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) call.

The following sequence of actions can be used to guarantee that application always has current protocol configuration information:

* Call **WSAProviderConfigChange**
* Call
  [WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) and/or
  [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)
* Whenever
  **WSAProviderConfigChange** notifies application of provider configuration change (through blocking or overlapped I/O), the whole sequence of actions should be repeated.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)