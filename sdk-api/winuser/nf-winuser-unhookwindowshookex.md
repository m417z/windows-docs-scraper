# UnhookWindowsHookEx function

## Description

Removes a hook procedure installed in a hook chain by the [SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa) function.

## Parameters

### `hhk` [in]

Type: **HHOOK**

A handle to the hook to be removed. This parameter is a hook handle obtained by a previous call to [SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa).

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The hook procedure can be in the state of being called by another thread even after **UnhookWindowsHookEx** returns. If the hook procedure is not being called concurrently, the hook procedure is removed immediately before **UnhookWindowsHookEx** returns.

#### Examples

For an example, see [Monitoring System Events](https://learn.microsoft.com/windows/desktop/winmsg/using-hooks).

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)