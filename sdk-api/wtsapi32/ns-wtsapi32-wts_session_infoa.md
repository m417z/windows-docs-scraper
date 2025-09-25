# WTS_SESSION_INFOA structure

## Description

Contains
information about a client session on a Remote Desktop Session Host (RD Session Host) server.

## Members

### `SessionId`

Session identifier of the session.

### `pWinStationName`

Pointer to a null-terminated string that contains the WinStation name of this session. The WinStation name is a name that Windows associates with the session, for example, "services", "console", or "RDP-Tcp#0".

### `State`

A value from the
[WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class) enumeration type
that indicates the session's current connection state.

## See also

[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)

[WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTS_SESSION_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).