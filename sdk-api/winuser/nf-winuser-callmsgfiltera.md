# CallMsgFilterA function

## Description

Passes the specified message and hook code to the hook procedures associated with the [WH_SYSMSGFILTER and WH_MSGFILTER](https://learn.microsoft.com/windows/desktop/winmsg/about-hooks) hooks. A **WH_SYSMSGFILTER** or **WH_MSGFILTER** hook procedure is an application-defined callback function that examines and, optionally, modifies messages for a dialog box, message box, menu, or scroll bar.

## Parameters

### `lpMsg` [in]

Type: **LPMSG**

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains the message to be passed to the hook procedures.

### `nCode` [in]

Type: **int**

An application-defined code used by the hook procedure to determine how to process the message. The code must not have the same value as system-defined hook codes (MSGF_ and HC_) associated with the [WH_SYSMSGFILTER](https://learn.microsoft.com/windows/desktop/winmsg/about-hooks) and **WH_MSGFILTER** hooks.

## Return value

Type: **BOOL**

If the application should process the message further, the return value is zero.

If the application should not process the message further, the return value is nonzero.

## Remarks

The system calls **CallMsgFilter** to enable applications to examine and control the flow of messages during internal processing of dialog boxes, message boxes, menus, and scroll bars, or when the user activates a different window by pressing the ALT+TAB key combination.

Install this hook procedure by using the [SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa) function.

#### Examples

For an example, see [WH_MSGFILTER and WH_SYSMSGFILTER Hooks](https://learn.microsoft.com/windows/desktop/winmsg/about-hooks).

> [!NOTE]
> The winuser.h header defines CallMsgFilter as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

[MessageProc](https://learn.microsoft.com/windows/win32/winmsg/messageproc)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)

[SysMsgProc](https://learn.microsoft.com/windows/win32/winmsg/sysmsgproc)