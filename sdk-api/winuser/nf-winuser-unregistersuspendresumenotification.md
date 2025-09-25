# UnregisterSuspendResumeNotification function

## Description

Cancels a registration to receive notification when the system is suspended or resumed. Similar to [PowerUnregisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerunregistersuspendresumenotification) but operates in user mode.

## Parameters

### `Handle` [in, out]

A handle to a registration obtained by calling the [RegisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registersuspendresumenotification) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[RegisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registersuspendresumenotification)