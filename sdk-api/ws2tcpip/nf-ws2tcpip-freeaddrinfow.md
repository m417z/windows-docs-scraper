# FreeAddrInfoW function

## Description

The
**FreeAddrInfoW** function frees address information that the
[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) function dynamically allocates in [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structures.

## Parameters

### `pAddrInfo` [in]

A pointer to the
[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure or linked list of
**addrinfoW** structures to be freed. All dynamic storage pointed to within the
**addrinfoW** structure or structures is also freed.

## Return value

This function does not return a value.

## Remarks

The
**FreeAddrInfoW** function frees [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structures dynamically allocated by the Unicode [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) function. The **FreeAddrInfoW** function frees the initial
**addrinfoW** structure pointed to in the *pAddrInfo* parameter, including any buffers to which structure members point, then continues freeing any
**addrinfoW** structures linked by the **ai_next** member of the **addrinfoW** structure. The
**FreeAddrInfoW** function continues freeing linked structures until a **NULL** **ai_next** member is encountered.

Macros in the Winsock header file define a mixed-case function name of **FreeAddrInfo** and an **ADDRINFOT** structure. This **FreeAddrInfo** function should be called with the *pAddrInfo* parameter of a pointer of type **ADDRINFOT**. When UNICODE or _UNICODE is defined, **FreeAddrInfo** is defined to **FreeAddrInfoW**, the Unicode version of the function, and **ADDRINFOT** is defined to the [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure. When UNICODE or _UNICODE is not defined, **FreeAddrInfo** is defined to [freeaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfo), the ANSI version of the function, and **ADDRINFOT** is defined to the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The ws2tcpip.h header defines FreeAddrInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)

[freeaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfo)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)