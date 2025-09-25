# EnableScrollBar function

## Description

The **EnableScrollBar** function enables or disables one or both scroll bar arrows.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a window or a scroll bar control, depending on the value of the
*wSBflags* parameter.

### `wSBflags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the scroll bar type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_BOTH** | Enables or disables the arrows on the horizontal and vertical scroll bars associated with the specified window. The *hWnd* parameter must be the handle to the window. |
| **SB_CTL** | Indicates that the scroll bar is a scroll bar control. The *hWnd* must be the handle to the scroll bar control. |
| **SB_HORZ** | Enables or disables the arrows on the horizontal scroll bar associated with the specified window. The *hWnd* parameter must be the handle to the window. |
| **SB_VERT** | Enables or disables the arrows on the vertical scroll bar associated with the specified window. The *hWnd* parameter must be the handle to the window. |

### `wArrows` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar arrows are enabled or disabled and indicates which arrows are enabled or disabled. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ESB_DISABLE_BOTH** | Disables both arrows on a scroll bar. |
| **ESB_DISABLE_DOWN** | Disables the down arrow on a vertical scroll bar. |
| **ESB_DISABLE_LEFT** | Disables the left arrow on a horizontal scroll bar. |
| **ESB_DISABLE_LTUP** | Disables the left arrow on a horizontal scroll bar or the up arrow of a vertical scroll bar. |
| **ESB_DISABLE_RIGHT** | Disables the right arrow on a horizontal scroll bar. |
| **ESB_DISABLE_RTDN** | Disables the right arrow on a horizontal scroll bar or the down arrow of a vertical scroll bar. |
| **ESB_DISABLE_UP** | Disables the up arrow on a vertical scroll bar. |
| **ESB_ENABLE_BOTH** | Enables both arrows on a scroll bar. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the arrows are enabled or disabled as specified, the return value is nonzero.

If the arrows are already in the requested state or an error occurs, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).