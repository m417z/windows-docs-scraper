# BSMINFO structure

## Description

Contains information about a window that denied a request from [BroadcastSystemMessageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessageexa).

## Members

### `cbSize`

Type: **UINT**

The size, in bytes, of this structure.

### `hdesk`

Type: **HDESK**

A desktop handle to the window specified by
**hwnd**. This value is returned only if [BroadcastSystemMessageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessageexa) specifies **BSF_RETURNHDESK** and **BSF_QUERY**.

### `hwnd`

Type: **HWND**

A handle to the window that denied the request. This value is returned if [BroadcastSystemMessageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessageexa) specifies **BSF_QUERY**.

### `luid`

Type: **LUID**

A locally unique identifier (LUID) for the window.

## See also

[BroadcastSystemMessageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessageexa)

**Conceptual**

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Reference**