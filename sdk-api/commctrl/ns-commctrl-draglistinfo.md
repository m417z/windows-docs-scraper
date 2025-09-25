# DRAGLISTINFO structure

## Description

Contains information about a drag event. The pointer to **DRAGLISTINFO** is passed as the
*lParam* parameter of the drag list message.

## Members

### `uNotification`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The notification code that specifies the type of drag event. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| **DL_BEGINDRAG** | The user has clicked the left mouse button on a list item. |
| **DL_CANCELDRAG** | The user has canceled the drag operation by clicking the right mouse button or pressing the ESC key. |
| **DL_DRAGGING** | The user has moved the mouse while dragging an item. |
| **DL_DROPPED** | The user has released the left mouse button, completing a drag operation. |

### `hWnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the drag list box.

### `ptCursor`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the current x- and y-coordinates of the mouse cursor.