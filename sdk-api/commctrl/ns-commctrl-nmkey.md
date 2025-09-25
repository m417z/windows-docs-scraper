# NMKEY structure

## Description

Contains information used with key notification messages.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about this notification.

### `nVKey`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A virtual key code of the key that caused the event.

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags associated with the key. These are the same flags that are passed in the high word of the
*lParam* parameter of the [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) message.