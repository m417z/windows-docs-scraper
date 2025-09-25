# ScrollWindow function

## Description

The **ScrollWindow** function scrolls the contents of the specified window's client area.

**Note** The **ScrollWindow** function is provided for backward compatibility. New applications should use the [ScrollWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-scrollwindowex) function.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the window where the client area is to be scrolled.

### `XAmount` [in]

Type: **int**

Specifies the amount, in device units, of horizontal scrolling. If the window being scrolled has the [CS_OWNDC](https://learn.microsoft.com/windows/desktop/winmsg/window-class-styles) or [CS_CLASSDC](https://learn.microsoft.com/windows/desktop/winmsg/window-class-styles) style, then this parameter uses logical units rather than device units. This parameter must be a negative value to scroll the content of the window to the left.

### `YAmount` [in]

Type: **int**

Specifies the amount, in device units, of vertical scrolling. If the window being scrolled has the [CS_OWNDC](https://learn.microsoft.com/windows/desktop/winmsg/window-class-styles) or [CS_CLASSDC](https://learn.microsoft.com/windows/desktop/winmsg/window-class-styles) style, then this parameter uses logical units rather than device units. This parameter must be a negative value to scroll the content of the window up.

### `lpRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure specifying the portion of the client area to be scrolled. If this parameter is **NULL**, the entire client area is scrolled.

### `lpClipRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to the
[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the clipping rectangle. Only device bits within the clipping rectangle are affected. Bits scrolled from the outside of the rectangle to the inside are painted; bits scrolled from the inside of the rectangle to the outside are not painted.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the caret is in the window being scrolled, **ScrollWindow** automatically hides the caret to prevent it from being erased and then restores the caret after the scrolling is finished. The caret position is adjusted accordingly.

The area uncovered by **ScrollWindow** is not repainted, but it is combined into the window's update region. The application eventually receives a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message notifying it that the region must be repainted. To repaint the uncovered area at the same time the scrolling is in action, call the [UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow) function immediately after calling **ScrollWindow**.

If the
*lpRect* parameter is **NULL**, the positions of any child windows in the window are offset by the amount specified by the
*XAmount* and
*YAmount* parameters; invalid (unpainted) areas in the window are also offset. **ScrollWindow** is faster when
*lpRect* is **NULL**.

If
*lpRect* is not **NULL**, the positions of child windows are not changed and invalid areas in the window are not offset. To prevent updating problems when
*lpRect* is not **NULL**, call
[UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow) to repaint the window before calling **ScrollWindow**.

#### Examples

For an example, see [Scrolling Text with the WM_PAINT Message](https://learn.microsoft.com/windows/desktop/Controls/using-scroll-bars).

## See also

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[ScrollDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-scrolldc)

[ScrollWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-scrollwindowex)

[UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow)