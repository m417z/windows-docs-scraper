# NMTREEVIEWW structure

## Description

Contains information about a tree-view notification message. This structure is identical to the
**NM_TREEVIEW** structure, but it has been renamed to follow current naming conventions.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification message.

### `action`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Notification-specific action flag. This member is used with the following notification codes.

* [TVN_ITEMEXPANDING](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanding)
* [TVN_ITEMEXPANDED](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanded)
* [TVN_SELCHANGING](https://learn.microsoft.com/windows/desktop/Controls/tvn-selchanging)
* [TVN_SELCHANGED](https://learn.microsoft.com/windows/desktop/Controls/tvn-selchanged)

For the possible action flag values, see [TVM_EXPAND](https://learn.microsoft.com/windows/desktop/Controls/tvm-expand) and [TVN_SELCHANGED](https://learn.microsoft.com/windows/desktop/Controls/tvn-selchanged).

### `itemOld`

Type: **[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemw)**

[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemw) structure that contains information about the old item state. This member is zero for notification messages that do not use it.

### `itemNew`

Type: **[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemw)**

[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemw) structure that contains information about the new item state. This member is zero for notification messages that do not use it.

### `ptDrag`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the client coordinates of the mouse at the time the event occurred that caused the notification message to be sent.

## See also

[WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify)

## Remarks

> [!NOTE]
> The commctrl.h header defines NMTREEVIEW as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).