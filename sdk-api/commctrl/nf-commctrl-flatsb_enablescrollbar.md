# FlatSB_EnableScrollBar function

## Description

Enables or disables one or both flat scroll bar direction buttons. If flat scroll bars are not initialized for the window, this function calls the standard [EnableScrollBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablescrollbar) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `unnamedParam2`

Type: **int**

A parameter that specifies the scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_BOTH** | Enables or disables the direction buttons on the horizontal and vertical scroll bars. |
| **SB_HORZ** | Enables or disables the direction buttons on the horizontal scroll bar. |
| **SB_VERT** | Enables or disables the direction buttons on the vertical scroll bar. |

### `unnamedParam3`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A parameter that specifies whether the scroll bar arrows are enabled or disabled and indicates which arrows are enabled or disabled. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **ESB_DISABLE_BOTH** | Disables both direction buttons on the specified scroll bar. |
| **ESB_DISABLE_DOWN** | Disables the down direction button on the vertical scroll bar. |
| **ESB_DISABLE_LEFT** | Disables the left direction button on the horizontal scroll bar. |
| **ESB_DISABLE_LTUP** | Disables the left direction button on the horizontal scroll bar or the up direction button on the vertical scroll bar. |
| **ESB_DISABLE_RIGHT** | Disables the right direction button on the horizontal scroll bar. |
| **ESB_DISABLE_RTDN** | Disables the right direction button on the horizontal scroll bar or the down direction button on the vertical scroll bar. |
| **ESB_DISABLE_UP** | Disables the up direction button on the vertical scroll bar. |
| **ESB_ENABLE_BOTH** | Enables both direction buttons on the specified scroll bar. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if the scroll bar changes, or zero otherwise.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.