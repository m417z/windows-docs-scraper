# GetTypeByNameA function

## Description

The
**GetTypeByName** function retrieves a service type **GUID** for a network service specified by name.

**Note** The
**GetTypeByName** function is a Microsoft-specific extension to the Windows Sockets 1.1 specification. This function is obsolete. For the convenience of Windows Sockets 1.1 developers, this reference material is included. The functions detailed in
[Protocol-Independent Name Resolution](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-name-resolution-2) provide equivalent functionality in Windows Sockets 2.

## Parameters

### `lpServiceName` [in]

A pointer to a zero-terminated string that uniquely represents the name of the service. For example, "MY SNA SERVER."

### `lpServiceType` [in, out]

A pointer to a variable to receive a globally unique identifier (**GUID**) that specifies the type of the network service. The *Svcguid.h* header file includes definitions of several **GUID** service types and macros for working with them.

The *Svcguid.h* header file is not automatically included by the *Winsock2.h* header file.

## Return value

If the function succeeds, the return value is zero.

If the function fails, the return value is SOCKET_ERROR( – 1). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which returns the following extended error value.

| Value | Meaning |
| --- | --- |
| **ERROR_SERVICE_DOES_NOT_EXIST** | The specified service type is unknown. |

## See also

[GetNameByType](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-getnamebytypea)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

## Remarks

> [!NOTE]
> The nspapi.h header defines GetTypeByName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).