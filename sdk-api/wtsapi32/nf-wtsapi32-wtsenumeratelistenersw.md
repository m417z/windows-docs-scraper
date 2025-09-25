# WTSEnumerateListenersW function

## Description

Enumerates all the Remote Desktop Services listeners on a Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Always set this parameter to
**WTS_CURRENT_SERVER_HANDLE**.

### `pReserved` [in]

This parameter is reserved. Always set this parameter to **NULL**.

### `Reserved` [in]

This parameter is reserved. Always set this parameter to zero.

### `pListeners` [out, optional]

A pointer to an array of **WTSLISTENERNAME** variables that receive the names of
the listeners.

### `pCount` [in, out]

A pointer to a **DWORD** variable that contains the number of listener names in
the array referenced by the *pListeners* parameter. If the number of listener names is
unknown, pass *pListeners* as **NULL**. The function will return
the number of **WTSLISTENERNAME** variables necessary to allocate for the array
pointed to by the *pListeners* parameter.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function returns all listeners currently running on the server, including listeners that do not support
Remote Desktop Protocol (RDP).

If the number of listeners is unknown, you can call this function with *pListeners*
set to **NULL**. The function will then return, in the *pCount*
parameter, the number of **WTSLISTENERNAME** variables necessary to receive all the
listeners. Allocate the array for *pListeners* based on this number, and then call the
function again, setting *pListeners* to the newly allocated array and
*pCount* to the number returned by the first call.

> [!NOTE]
> The wtsapi32.h header defines WTSEnumerateListeners as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).