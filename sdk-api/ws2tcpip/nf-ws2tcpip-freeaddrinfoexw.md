# FreeAddrInfoExW function

## Description

The
**FreeAddrInfoEx** function frees address information that the
[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function dynamically allocates in [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structures.

## Parameters

### `pAddrInfoEx` [in]

A pointer to the
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure or linked list of
**addrinfoex** structures to be freed. All dynamic storage pointed to within the
**addrinfoex** structure or structures is also freed.

## Return value

This function does not return a value.

## Remarks

The
**FreeAddrInfoEx** function frees [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structures dynamically allocated by the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function. The **FreeAddrInfoEx** function frees the initial
**addrinfoex** structure pointed to in the *pAddrInfo* parameter, including any buffers to which structure members point, then continues freeing any
**addrinfoex** structures linked by the **ai_next** member of the **addrinfoex** structure. The
**FreeAddrInfoEx** function continues freeing linked structures until a **NULL** **ai_next** member is encountered.

When UNICODE or _UNICODE is defined, **FreeAddrInfoEx** is defined to **FreeAddrInfoExW**, the Unicode version of the function, and **ADDRINFOEX** is defined to the [addrinfoexW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure. When UNICODE or _UNICODE is not defined, **FreeAddrInfoEx** is defined to **FreeAddrInfoExA**, the ANSI version of the function, and **ADDRINFOEX** is defined to the **addrinfoexA** structure.

**Windows 8.1** and **Windows Server 2012 R2**: The **FreeAddrInfoExW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The ws2tcpip.h header defines FreeAddrInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw)