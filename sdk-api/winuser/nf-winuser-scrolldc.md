# ScrollDC function

## Description

The **ScrollDC** function scrolls a rectangle of bits horizontally and vertically.

## Parameters

### `hDC` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the device context that contains the bits to be scrolled.

### `dx` [in]

Type: **int**

Specifies the amount, in device units, of horizontal scrolling. This parameter must be a negative value to scroll to the left.

### `dy` [in]

Type: **int**

Specifies the amount, in device units, of vertical scrolling. This parameter must be a negative value to scroll up.

### `lprcScroll` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the bits to be scrolled. The only bits affected by the scroll operation are bits in the intersection of this rectangle and the rectangle specified by
*lprcClip*. If
*lprcScroll* is **NULL**, the entire client area is used.

### `lprcClip` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a
[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the clipping rectangle. The only bits that will be painted are the bits that remain inside this rectangle after the scroll operation has been completed. If
*lprcClip* is **NULL**, the entire client area is used.

### `hrgnUpdate` [in]

Type: **[HRGN](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the region uncovered by the scrolling process. **ScrollDC** defines this region; it is not necessarily a rectangle.

### `lprcUpdate` [out]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the coordinates of the rectangle bounding the scrolling update region. This is the largest rectangular area that requires repainting. When the function returns, the values in the structure are in client coordinates, regardless of the mapping mode for the specified device context. This allows applications to use the update region in a call to the [InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn) function, if required.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the
*lprcUpdate* parameter is **NULL**, the system does not compute the update rectangle. If both the
*hrgnUpdate* and
*lprcUpdate* parameters are **NULL**, the system does not compute the update region. If
*hrgnUpdate* is not **NULL**, the system proceeds as though it contains a valid handle to the region uncovered by the scrolling process (defined by **ScrollDC**).

When you must scroll the entire client area of a window, use the [ScrollWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-scrollwindowex) function.

## See also

[InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[ScrollWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-scrollwindowex)