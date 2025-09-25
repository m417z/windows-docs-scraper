# ChangeWindowMessageFilter function

## Description

[Using the
**ChangeWindowMessageFilter** function is not recommended, as it has process-wide scope.
Instead, use the [ChangeWindowMessageFilterEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilterex) function to
control access to specific windows as needed.
**ChangeWindowMessageFilter** may not be supported in future versions of Windows.]

Adds or removes a message from the User Interface Privilege Isolation (UIPI) message filter.

## Parameters

### `message` [in]

Type: **UINT**

The message to add to or remove from the filter.

### `dwFlag` [in]

Type: **DWORD**

The action to be performed. One of the following values.

| Value | Meaning |
| --- | --- |
| **MSGFLT_ADD**<br><br>1 | Adds the *message* to the filter. This has the effect of allowing the message to be received. |
| **MSGFLT_REMOVE**<br><br>2 | Removes the *message* from the filter. This has the effect of blocking the message. |

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** A message can be successfully removed from the filter, but that is not a guarantee that the message will be blocked. See the Remarks section for more details.

## Remarks

UIPI is a security feature that prevents messages from being received from a lower integrity level sender. All such messages with a value above **WM_USER** are blocked by default. The filter, somewhat contrary to intuition, is a list of messages that are allowed through. Therefore, adding a message to the filter allows that message to be received from a lower integrity sender, while removing a message blocks that message from being received.

Certain messages with a value less than **WM_USER** are required to pass through the filter regardless of the filter setting. You can call this function to remove one of those messages from the filter and it will return **TRUE**. However, the message will still be received by the calling process.

Processes at or below **SECURITY_MANDATORY_LOW_RID** are not allowed to change the filter. If those processes call this function, it will fail.

For more information on integrity levels, see [Understanding and Working in Protected Mode Internet Explorer](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/).