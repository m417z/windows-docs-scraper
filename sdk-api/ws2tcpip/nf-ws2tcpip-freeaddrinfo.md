# freeaddrinfo function

## Description

The
**freeaddrinfo** function frees address information that the
[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function dynamically allocates in [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structures.

## Parameters

### `pAddrInfo` [in]

A pointer to the
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure or linked list of
**addrinfo** structures to be freed. All dynamic storage pointed to within the
**addrinfo** structure or structures is also freed.

## Return value

This function does not return a value.

## Remarks

The
**freeaddrinfo** function frees [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structures dynamically allocated by the ANSI [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function. The **freeaddrinfo** function frees the initial
**addrinfo** structure pointed to in the *ai* parameter, including any buffers to which structure members point, then continues freeing any
**addrinfo** structures linked by the **ai_next** member of the **addrinfo** structure. The
**freeaddrinfo** function continues freeing linked structures until a **NULL** **ai_next** member is encountered.

Macros in the Winsock header file define a mixed-case function name of **FreeAddrInfo** and an **ADDRINFOT** structure. This **FreeAddrInfo** function should be called with the *ai* parameter of a pointer of type **ADDRINFOT**. When UNICODE or _UNICODE is not defined, **FreeAddrInfo** is defined to **freeaddrinfo**, the ANSI version of the function, and **ADDRINFOT** is defined to the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure. When UNICODE or _UNICODE is defined, **FreeAddrInfo** is defined to [FreeAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfow), the Unicode version of the function, and **ADDRINFOT** is defined to the [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure.

### Support for freeaddrinfo on earlier versions of Windows

The **freeaddrinfo** function was added to the *Ws2_32.dll* on Windows XP and later.

The [FreeAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfow) function is the Unicode version of **freeaddrinfo**. The **FreeAddrInfoW** function was added to the *Ws2_32.dll* in Windows XP with Service Pack 2 (SP2). The **FreeAddrInfoW** function cannot be used on versions of Windows earlier than Windows XP with SP2.

**Windows Phone 8:** The **freeaddrinfo** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **freeaddrinfo** and [FreeAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfow) functions are supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[FreeAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfow)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)