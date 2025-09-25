# IsDialogMessageW function

## Description

Determines whether a message is intended for the specified dialog box and, if it is, processes the message.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box.

### `lpMsg` [in]

Type: **LPMSG**

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains the message to be checked.

## Return value

Type: **BOOL**

If the message has been processed, the return value is nonzero.

If the message has not been processed, the return value is zero.

## Remarks

Although the **IsDialogMessage** function is intended for modeless dialog boxes, you can use it with any window that contains controls, enabling the windows to provide the same keyboard selection as is used in a dialog box.

When **IsDialogMessage** processes a message, it checks for keyboard messages and converts them into selections for the corresponding dialog box. For example, the TAB key, when pressed, selects the next control or group of controls, and the DOWN ARROW key, when pressed, selects the next control in a group.

Because the **IsDialogMessage** function performs all necessary translating and dispatching of messages, a message processed by **IsDialogMessage** must not be passed to the [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) or [DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage) function.

**IsDialogMessage** sends [WM_GETDLGCODE](https://learn.microsoft.com/windows/desktop/dlgbox/wm-getdlgcode) messages to the dialog box procedure to determine which keys should be processed.

**IsDialogMessage** can send [DM_GETDEFID](https://learn.microsoft.com/windows/desktop/dlgbox/dm-getdefid) and [DM_SETDEFID](https://learn.microsoft.com/windows/desktop/dlgbox/dm-setdefid) messages to the window. These messages are defined in the Winuser.h header file as [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user) and **WM_USER** + 1, so conflicts are possible with application-defined messages having the same values.

> [!NOTE]
> The winuser.h header defines IsDialogMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DM_GETDEFID](https://learn.microsoft.com/windows/desktop/dlgbox/dm-getdefid)

[DM_SETDEFID](https://learn.microsoft.com/windows/desktop/dlgbox/dm-setdefid)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

**Reference**

[TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage)

[WM_GETDLGCODE](https://learn.microsoft.com/windows/desktop/dlgbox/wm-getdlgcode)

[WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)