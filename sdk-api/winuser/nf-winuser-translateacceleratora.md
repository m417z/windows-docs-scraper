# TranslateAcceleratorA function

## Description

Processes accelerator keys for menu commands. The function translates a [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) or [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown) message to a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) or [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) message (if there is an entry for the key in the specified accelerator table) and then sends the **WM_COMMAND** or **WM_SYSCOMMAND** message directly to the specified window procedure. **TranslateAccelerator** does not return until the window procedure has processed the message.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose messages are to be translated.

### `hAccTable` [in]

Type: **HACCEL**

A handle to the accelerator table. The accelerator table must have been loaded by a call to the [LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa) function or created by a call to the [CreateAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createacceleratortablea) function.

### `lpMsg` [in]

Type: **LPMSG**

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains message information retrieved from the calling thread's message queue using the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function.

## Return value

Type: **int**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To differentiate the message that this function sends from messages sent by menus or controls, the high-order word of the
*wParam* parameter of the [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) or [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) message contains the value 1.

Accelerator key combinations used to select items from the
**window** menu are translated into [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) messages; all other accelerator key combinations are translated into [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages.

When **TranslateAccelerator** returns a nonzero value and the message is translated, the application should not use the [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) function to process the message again.

An accelerator need not correspond to a menu command.

If the accelerator command corresponds to a menu item, the application is sent [WM_INITMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenu) and [WM_INITMENUPOPUP](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenupopup) messages, as if the user were trying to display the menu. However, these messages are not sent if any of the following conditions exist:

* The window is disabled.
* The accelerator key combination does not correspond to an item on the **window** menu and the window is minimized.
* A mouse capture is in effect. For information about mouse capture, see the [SetCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcapture) function.

If the specified window is the active window and no window has the keyboard focus (which is generally the case if the window is minimized), **TranslateAccelerator** translates
[WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup) and [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown) messages instead of
[WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup) and [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) messages.

If an accelerator keystroke occurs that corresponds to a menu item when the window that owns the menu is minimized, **TranslateAccelerator** does not send a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message. However, if an accelerator keystroke occurs that does not match any of the items in the window's menu or in the
**window** menu, the function sends a **WM_COMMAND** message, even if the window is minimized.

#### Examples

For an example, see [Creating Accelerators for Font Attributes](https://learn.microsoft.com/windows/desktop/menurc/using-keyboard-accelerators).

> [!NOTE]
> The winuser.h header defines TranslateAccelerator as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createacceleratortablea)

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Keyboard Accelerators](https://learn.microsoft.com/windows/desktop/menurc/keyboard-accelerators)

[LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

**Reference**

[SetCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcapture)

[TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage)

[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command)

[WM_INITMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenu)

[WM_INITMENUPOPUP](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenupopup)

[WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)

[WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand)

[WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown)