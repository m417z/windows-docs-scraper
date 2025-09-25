# IsWinEventHookInstalled function

## Description

Determines whether there is an installed WinEvent hook that might be notified of a specified event.

## Parameters

### `event` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The event constant that hooks might be notified of. The function checks whether there is an installed hook for this event constant.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If there is a hook to be notified of the specified event, the return value is **TRUE**.

If there are no hooks to be notified of the specified event, the return value is **FALSE**.

## Remarks

This method is guaranteed to never return a false negative. If this method returns **FALSE**, it means that no hooks in the system would be notified of the event. However, this method may return a false positive. In other words, it may return **TRUE** even though there are no hooks that would be notified. Thus, it is safe for components to circumvent some work if this method returns **FALSE**.

Event hooks can be installed at any time, so server developers should not cache the return value for long periods of time.

## See also

[SetWinEventHook](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwineventhook)

[UnhookWinEvent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unhookwinevent)