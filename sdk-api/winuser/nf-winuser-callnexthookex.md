# CallNextHookEx function

## Description

Passes the hook information to the next hook procedure in the current hook chain. A hook procedure can call this function either before or after processing the hook information.

## Parameters

### `hhk` [in, optional]

Type: **HHOOK**

This parameter is ignored.

### `nCode` [in]

Type: **int**

The hook code passed to the current hook procedure. The next hook procedure uses this code to determine how to process the hook information.

### `wParam` [in]

Type: **WPARAM**

The *wParam* value passed to the current hook procedure. The meaning of this parameter depends on the type of hook associated with the current hook chain.

### `lParam` [in]

Type: **LPARAM**

The *lParam* value passed to the current hook procedure. The meaning of this parameter depends on the type of hook associated with the current hook chain.

## Return value

Type: **LRESULT**

This value is returned by the next hook procedure in the chain. The current hook procedure must also return this value. The meaning of the return value depends on the hook type. For more information, see the descriptions of the individual hook procedures.

## Remarks

Hook procedures are installed in chains for particular hook types. **CallNextHookEx** calls the next hook in the chain.

Calling **CallNextHookEx** is optional, but it is highly recommended; otherwise, other applications that have installed hooks will not receive hook notifications and may behave incorrectly as a result. You should call **CallNextHookEx** unless you absolutely need to prevent the notification from being seen by other applications.

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)

[UnhookWindowsHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-unhookwindowshookex)