# CalculatePopupWindowPosition function

## Description

Calculates an appropriate pop-up window position using the specified anchor point, pop-up window size, flags, and the optional exclude rectangle. When the specified pop-up window size is smaller than the desktop window size, use the **CalculatePopupWindowPosition** function to ensure that the pop-up window is fully visible on the desktop window, regardless of the specified anchor point.

## Parameters

### `anchorPoint` [in]

Type: **const POINT***

The specified anchor point.

### `windowSize` [in]

Type: **const SIZE***

The specified window size.

### `flags` [in]

Type: **UINT**

Use one of the following flags to specify how the function positions the pop-up window horizontally and vertically. The flags are the same as the vertical and horizontal positioning flags of the [TrackPopupMenuEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenuex) function.

Use one of the following flags to specify how the function positions the pop-up window horizontally.

| Value | Meaning |
| --- | --- |
| **TPM_CENTERALIGN**<br><br>0x0004L | Centers pop-up window horizontally relative to the coordinate specified by the anchorPoint->x parameter. |
| **TPM_LEFTALIGN**<br><br>0x0000L | Positions the pop-up window so that its left edge is aligned with the coordinate specified by the anchorPoint->x parameter. |
| **TPM_RIGHTALIGN**<br><br>0x0008L | Positions the pop-up window so that its right edge is aligned with the coordinate specified by the anchorPoint->x parameter. |

Uses one of the following flags to specify how the function positions the pop-up window vertically.

| Value | Meaning |
| --- | --- |
| **TPM_BOTTOMALIGN**<br><br>0x0020L | Positions the pop-up window so that its bottom edge is aligned with the coordinate specified by the anchorPoint->y parameter. |
| **TPM_TOPALIGN**<br><br>0x0000L | Positions the pop-up window so that its top edge is aligned with the coordinate specified by the anchorPoint->y parameter. |
| **TPM_VCENTERALIGN**<br><br>0x0010L | Centers the pop-up window vertically relative to the coordinate specified by the anchorPoint->y parameter. |

Use one of the following flags to specify whether to accommodate horizontal or vertical alignment.

| Value | Meaning |
| --- | --- |
| **TPM_HORIZONTAL**<br><br>0x0000L | If the pop-up window cannot be shown at the specified location without overlapping the excluded rectangle, the system tries to accommodate the requested horizontal alignment before the requested vertical alignment. |
| **TPM_VERTICAL**<br><br>0x0040L | If the pop-up window cannot be shown at the specified location without overlapping the excluded rectangle, the system tries to accommodate the requested vertical alignment before the requested horizontal alignment. |

The following flag
is available starting with Windows 7.

| Value | Meaning |
| --- | --- |
| **TPM_WORKAREA**<br><br>0x10000L | Restricts the pop-up window to within the work area. If this flag is not set, the pop-up window is restricted to the work area only if the input point is within the work area. For more information, see the **rcWork** and **rcMonitor** members of the [MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) structure. |

### `excludeRect` [in, optional]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a structure that specifies the exclude rectangle.
It can be **NULL**.

### `popupWindowPosition` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a structure that specifies the pop-up window position.

## Return value

Type: **BOOL**

If the function succeeds, it returns **TRUE**; otherwise, it returns **FALSE**.
To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**TPM_WORKAREA** is supported for the [TrackPopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) and [TrackPopupMenuEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenuex) functions.

## See also

**Reference**

[TrackPopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenu)

[TrackPopupMenuEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenuex)