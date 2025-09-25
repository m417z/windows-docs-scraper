# IsDestinationReachableA function

## Description

The
**IsDestinationReachable** function determines whether or not a specified destination can be reached, and provides Quality of Connection (QOC) information for a destination.

**Windows Vista and later, Windows Server 2008 and later:** This function is not supported and always returns **ERROR_CALL_NOT_IMPLEMENTED**.

## Parameters

### `lpszDestination` [in]

A pointer to a **null**-terminated string that specifies a destination. The destination can be an IP address, UNC name, or URL.

### `lpQOCInfo` [in, out]

A pointer to the
[QOCINFO](https://learn.microsoft.com/windows/desktop/api/sensapi/ns-sensapi-qocinfo) structure that receives the Quality of Connection (QOC) information. You can supply a **NULL** pointer if you do not want to receive the QOC information.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | A destination can be reached. |
| **FALSE** | A destination cannot be reached. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |
| **ERROR_CALL_NOT_IMPLEMENTED** | This function is not available on Windows Vista. |

## Remarks

Client applications use this function to determine the QOC information before proceeding with network operations. For standalone computers that are directly connected to a network through a network card or remote access server (RAS), this function generates minimal network traffic with RPC calls to the nearest router. For computers that are part of a network where a destination can be reached by using RAS or a network gateway, this function pings a destination to generate accurate QOC information.

This function is only available for TCP/IP connections. A caller supplies the buffer for the
[QOCINFO](https://learn.microsoft.com/windows/desktop/api/sensapi/ns-sensapi-qocinfo) structure, and must release the memory when it is not needed.

Starting with applications designed for Windows Vista and Windows Server 2008, developers should consider using the [Network List Manager](https://learn.microsoft.com/windows/desktop/NLA/portal) instead of this function.

> [!NOTE]
> The sensapi.h header defines IsDestinationReachable as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IsNetworkAlive](https://learn.microsoft.com/windows/desktop/api/sensapi/nf-sensapi-isnetworkalive)

[QOCINFO](https://learn.microsoft.com/windows/desktop/api/sensapi/ns-sensapi-qocinfo)