# WTSEnumerateSessionsW function

## Description

Retrieves a list of sessions on a Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `hServer` [in]

A handle to the RD Session Host server.

**Note** You can use the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) or [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) functions to retrieve a handle to a specific server, or **WTS_CURRENT_SERVER_HANDLE** to use the RD Session Host server that hosts your application.

### `Reserved` [in]

This parameter is reserved. It must be zero.

### `Version` [in]

The version of the enumeration request. This parameter must be 1.

### `ppSessionInfo` [out]

A pointer to an array of [WTS_SESSION_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_infoa) structures that represent the retrieved sessions. To free the returned buffer, call the
[WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory) function.

**Session permissions:**

* To enumerate a session, you must enable the query information permission. For more information, see
  [Remote Desktop Services Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions).
* To change permissions on a session, use the Remote Desktop Services Configuration administrative tool.
* To enumerate sessions running on a virtual machine hosted on a RD Virtualization Host server, you must be a member of the Administrators group on the RD Virtualization Host server.

### `pCount` [out]

A pointer to the number of
**WTS_SESSION_INFO** structures returned in the *ppSessionInfo* parameter.

## Return value

Returns zero if this function fails. If this function succeeds, a nonzero value is returned.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSEnumerateSessions as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTS_SESSION_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_infoa)