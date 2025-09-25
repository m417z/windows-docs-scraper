# BroadcastSystemMessageExA function

## Description

Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.

This function is similar to [BroadcastSystemMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessage) except that this function can return more information from the recipients.

## Parameters

### `flags` [in]

Type: **DWORD**

The broadcast option. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **BSF_ALLOWSFW**<br><br>0x00000080 | Enables the recipient to set the foreground window while processing the message. |
| **BSF_FLUSHDISK**<br><br>0x00000004 | Flushes the disk after each recipient processes the message. |
| **BSF_FORCEIFHUNG**<br><br>0x00000020 | Continues to broadcast the message, even if the time-out period elapses or one of the recipients is not responding. |
| **BSF_IGNORECURRENTTASK**<br><br>0x00000002 | Does not send the message to windows that belong to the current task. This prevents an application from receiving its own message. |
| **BSF_LUID**<br><br>0x00000400 | If **BSF_LUID** is set, the message is sent to the window that has the same LUID as specified in the **luid** member of the [BSMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-bsminfo) structure.<br><br>**Windows 2000:** This flag is not supported. |
| **BSF_NOHANG**<br><br>0x00000008 | Forces a nonresponsive application to time out. If one of the recipients times out, do not continue broadcasting the message. |
| **BSF_NOTIMEOUTIFNOTHUNG**<br><br>0x00000040 | Waits for a response to the message, as long as the recipient is not being unresponsive. Does not time out. |
| **BSF_POSTMESSAGE**<br><br>0x00000010 | Posts the message. Do not use in combination with **BSF_QUERY**. |
| **BSF_RETURNHDESK**<br><br>0x00000200 | If access is denied and both this and **BSF_QUERY** are set, [BSMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-bsminfo) returns both the desktop handle and the window handle. If access is denied and only **BSF_QUERY** is set, only the window handle is returned by **BSMINFO**.<br><br>**Windows 2000:** This flag is not supported. |
| **BSF_QUERY**<br><br>0x00000001 | Sends the message to one recipient at a time, sending to a subsequent recipient only if the current recipient returns **TRUE**. |
| **BSF_SENDNOTIFYMESSAGE**<br><br>0x00000100 | Sends the message using [SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea) function. Do not use in combination with **BSF_QUERY**. |

### `lpInfo` [in, out, optional]

Type: **LPDWORD**

A pointer to a variable that contains and receives information about the recipients of the message.

When the function returns, this variable receives a combination of these values identifying which recipients actually received the message.

If this parameter is **NULL**, the function broadcasts to all components.

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **BSM_ALLCOMPONENTS**<br><br>0x00000000 | Broadcast to all system components. |
| **BSM_ALLDESKTOPS**<br><br>0x00000010 | Broadcast to all desktops. Requires the [SE_TCB_NAME](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants) privilege. |
| **BSM_APPLICATIONS**<br><br>0x00000008 | Broadcast to applications. |

### `Msg` [in]

Type: **UINT**

The message to be sent.

For lists of the system-provided messages, see [System-Defined Messages](https://learn.microsoft.com/windows/desktop/winmsg/about-messages-and-message-queues).

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

### `pbsmInfo` [out, optional]

Type: **PBSMINFO**

A pointer to a [BSMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-bsminfo) structure that contains additional information if the request is denied and *dwFlags* is set to **BSF_QUERY**.

## Return value

Type: **long**

If the function succeeds, the return value is a positive value.

If the function is unable to broadcast the message, the return value is –1.

If the *dwFlags* parameter is **BSF_QUERY** and at least one recipient returned **BROADCAST_QUERY_DENY** to the corresponding message, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If **BSF_QUERY** is not specified, the function sends the specified message to all requested recipients, ignoring values returned by those recipients.

If the caller's thread is on a desktop other than that of the window that denied the request, the caller must call [SetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddesktop)**(hdesk)** to query anything on that window. Also, the caller must call [CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop) on the returned **hdesk** handle.

The system only does marshalling for system messages (those in the range 0 to ([WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)-1)). To send other messages (those >= **WM_USER**) to another process, you must do custom marshalling.

> [!NOTE]
> The winuser.h header defines BroadcastSystemMessageEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BSMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-bsminfo)

[BroadcastSystemMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessage)

**Conceptual**

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**

[SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea)