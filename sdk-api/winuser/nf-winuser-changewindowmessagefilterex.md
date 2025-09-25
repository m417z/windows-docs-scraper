# ChangeWindowMessageFilterEx function

## Description

Modifies the User Interface Privilege Isolation (UIPI) message filter for a specified window.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window whose UIPI message filter is to be modified.

### `message` [in]

Type: **UINT**

The message that the message filter allows through or blocks.

### `action` [in]

Type: **DWORD**

The action to be performed, and can take one of the following values:

| Value | Meaning |
| --- | --- |
| **MSGFLT_ALLOW**<br><br>1 | Allows the message through the filter. This enables the message to be received by *hWnd*, regardless of the source of the message, even it comes from a lower privileged process. |
| **MSGFLT_DISALLOW**<br><br>2 | Blocks the message to be delivered to *hWnd* if it comes from a lower privileged process, unless the message is allowed process-wide by using the [ChangeWindowMessageFilter](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilter) function or globally. |
| **MSGFLT_RESET**<br><br>0 | Resets the window message filter for *hWnd* to the default. Any message allowed globally or process-wide will get through, but any message not included in those two categories, and which comes from a lower privileged process, will be blocked. |

### `pChangeFilterStruct` [in, out, optional]

Type: **PCHANGEFILTERSTRUCT**

Optional pointer to a [CHANGEFILTERSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-changefilterstruct) structure.

## Return value

Type: **BOOL**

If the function succeeds, it returns **TRUE**; otherwise, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

UIPI is a security feature that prevents messages from being received from a lower-integrity-level sender.
You can use this function to allow specific messages to be delivered to a window even
if the message originates from a process at a lower integrity level. Unlike the [ChangeWindowMessageFilter](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilter) function,
which controls the process message filter, the **ChangeWindowMessageFilterEx** function controls the window message filter.

An application may use the [ChangeWindowMessageFilter](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilter) function to
allow or block a message in a process-wide manner.
If the message is allowed by either the process message filter
or the window message filter, it will be delivered to the window.

Note that processes at or below **SECURITY_MANDATORY_LOW_RID** are not allowed to change the message filter.
If those processes call this function, it will fail and generate the extended error code, **ERROR_ACCESS_DENIED**.

Certain messages whose value is smaller than **WM_USER** are required to be passed through the filter,
regardless of the filter setting. There will be no effect when you attempt to use this function to
allow or block such messages.

## See also

[ChangeWindowMessageFilter](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilter)

**Conceptual**

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)