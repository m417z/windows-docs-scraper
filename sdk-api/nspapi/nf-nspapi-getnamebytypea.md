# GetNameByTypeA function

## Description

The
**GetNameByType** function retrieves the name of a network service for the specified service type.

**Note** The
**GetNameByType** function is a Microsoft-specific extension to the Windows Sockets 1.1 specification. This function is obsolete. For the convenience of Windows Sockets 1.1 developers, the reference material is as follows.

**Note** The functions detailed in
[Protocol-Independent Name Resolution](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-name-resolution-2) provide equivalent functionality in Windows Sockets 2.

## Parameters

### `lpServiceType` [in]

A pointer to a globally unique identifier (GUID) that specifies the type of the network service. The *Svcguid.h* header file includes definitions of several GUID service types, and macros for working with them.

The *Svcguid.h* header file is not automatically included by the *Winsock2.h* header file.

### `lpServiceName` [out]

A pointer to a buffer to receive a zero-terminated string that uniquely represents the name of the network service.

### `dwNameLength` [in]

A pointer to a variable that, on input, specifies the size, in bytes, of the buffer pointed to by *lpServiceName*. On output, the variable contains the actual size of the service name string, in bytes.

## Return value

If the function succeeds, the return value is not SOCKET_ERROR (–1).

If the function fails, the return value is SOCKET_ERROR (–1). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetTypeByName](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-gettypebynamea)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

## Remarks

> [!NOTE]
> The nspapi.h header defines GetNameByType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).