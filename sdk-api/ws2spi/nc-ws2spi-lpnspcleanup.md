## Description

The **NSPCleanup** function terminates the use of a particular Windows Sockets namespace service provider.

## Parameters

### `lpProviderId` [in]

A pointer to the [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) of the namespace provider to be terminated.

## Return value

If no error occurs, then **NSPCleanup** returns a value of **NO_ERROR** (zero). Otherwise, **SOCKET_ERROR** (–1) is returned, and the provider must set the appropriate error code using [WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

|Error code|Meaning|
|-|-|
|**[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)**|There is not enough memory available to perform this operation.|
|**[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)**|The *lpProviderId* parameter doesn't specify a valid provider.|
|**[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)**|The operation is not supported. This error is returned if the namespace provider does not implement this function.|

## Remarks

The **NSPCleanup** function is called when an application is finished using a Windows Sockets namespace service provider. The **NSPCleanup** function deregisters a particular namespace provider and allows the transport service provider to free any of the namespace provider's allocated resources.

The [NSPStartup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-nspstartup) function must be called successfully before using any namespace providers. It is permissible to make more than one
**NSPStartup** call. However, for each
**NSPStartup** call, a corresponding
**NSPCleanup** call must also be issued. Only the final
**NSPCleanup** for the service provider does the actual cleanup; the preceding calls decrement an internal reference count in the service provider.

This function should not return until the namespace service provider DLL can be unloaded from memory.

## See also

* [NSPStartup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-nspstartup)
* [WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)