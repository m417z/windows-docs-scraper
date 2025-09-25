# EVENTMSG structure

## Description

Contains information about a hardware message sent to the system message queue. This structure is used to store message information for the [JournalPlaybackProc](https://learn.microsoft.com/windows/win32/winmsg/journalplaybackproc) callback function.

## Members

### `message`

Type: **UINT**

The message.

### `paramL`

Type: **UINT**

Additional information about the message. The exact meaning depends on the
**message** value.

### `paramH`

Type: **UINT**

Additional information about the message. The exact meaning depends on the
**message** value.

### `time`

Type: **DWORD**

The time at which the message was posted.

### `hwnd`

Type: **HWND**

A handle to the window to which the message was posted.

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[JournalPlaybackProc](https://learn.microsoft.com/windows/win32/winmsg/journalplaybackproc)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)