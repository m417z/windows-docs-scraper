# LowLevelKeyboardProc function

## Description

An application-defined or library-defined callback function used with the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function. The system calls this function every time a new keyboard input event is about to be posted into a thread input queue.

>[!NOTE]
> When this callback function is called in response to a change in the state of a key, the callback function is called before the asynchronous state of the key is updated. Consequently, the asynchronous state of the key cannot be determined by calling [**GetAsyncKeyState**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate) from within the callback function.

The **HOOKPROC** type defines a pointer to this callback function. **LowLevelKeyboardProc** is a placeholder for the application-defined or library-defined function name.

```c++
LRESULT CALLBACK LowLevelKeyboardProc(
  _In_ int    nCode,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
);
```

## Parameters

### code [in]

Type: **int**

A code the hook procedure uses to determine how to process the message.

If *nCode* is less than zero, the hook procedure must pass the message to the [CallNextHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callnexthookex) function without further processing and should return the value returned by **CallNextHookEx**.

This parameter can be one of the following values.

| Value | Meaning |
|-------|---------|
| **HC_ACTION** 0 | The *wParam* and *lParam* parameters contain information about a keyboard message. |

### wParam [in]

Type: **WPARAM**

The identifier of the keyboard message.

This parameter can be one of the following messages: [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown), [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup), [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown), or [WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup).

### lParam [in]

Type: **LPARAM**

A pointer to a [KBDLLHOOKSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-kbdllhookstruct) structure.

## Returns

Type: **LRESULT**

If *nCode* is less than zero, the hook procedure must return the value returned by [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex).

If *nCode* is greater than or equal to zero, and the hook procedure did not process the message, it is highly recommended that you call [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) and return the value it returns; otherwise, other applications that have installed [**WH_KEYBOARD_LL**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hooks will not receive hook notifications and may behave incorrectly as a result.

If the hook procedure processed the message, it may return a nonzero value to prevent the system from passing the message to the rest of the hook chain or the target window procedure.

## Remarks

An application installs the hook procedure by specifying the [**WH_KEYBOARD_LL**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook type and a pointer to the hook procedure in a call to the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function.

This hook is called in the context of the thread that installed it. The call is made by sending a message to the thread that installed the hook. Therefore, the thread that installed the hook must have a message loop.

The keyboard input can come from the local keyboard driver or from calls to the [**keybd_event**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-keybd_event) function. If the input comes from a call to **keybd_event**, the input was "injected". However, the [**WH_KEYBOARD_LL**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook is not injected into another process. Instead, the context switches back to the process that installed the hook and it is called in its original context. Then the context switches back to the application that generated the event.

The hook procedure should process a message in less time than the data entry specified in the **LowLevelHooksTimeout** value in the following registry key:

`HKEY_CURRENT_USER**\**Control Panel**\**Desktop`

The value is in milliseconds. If the hook procedure times out, the system passes the message to the next hook. However, on Windows 7 and later, the hook is silently removed without being called. There is no way for the application to know whether the hook is removed.

**Windows 10 version 1709 and later** The maximum timeout value the system allows is 1000 milliseconds (1 second). The system will default to using a 1000 millisecond timeout if the **LowLevelHooksTimeout** value is set to a value larger than 1000.

> [!NOTE]
> Debug hooks cannot track this type of low level keyboard hooks. If the application must use low level hooks, it should run the hooks on a dedicated thread that passes the work off to a worker thread and then immediately returns. In most cases where the application needs to use low level hooks, it should monitor raw input instead. This is because raw input can asynchronously monitor mouse and keyboard messages that are targeted for other threads more effectively than low level hooks can. For more information on raw input, see [Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input).

## See also

[CallNextHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callnexthookex)

[KBDLLHOOKSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-kbdllhookstruct)

[keybd_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-keybd_event)

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexw)

[WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)

[WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup)

[WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown)

[WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup)

[Hooks](https://learn.microsoft.com/windows/win32/winmsg/hooks)

[About Hooks](https://learn.microsoft.com/windows/win32/winmsg/about-hooks)