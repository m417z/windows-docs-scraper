# PAINTSTRUCT structure

## Description

The **PAINTSTRUCT** structure contains information for an application. This information can be used to paint the client area of a window owned by that application.

## Members

### `hdc`

A handle to the display DC to be used for painting.

### `fErase`

Indicates whether the background must be erased. This value is nonzero if the application should erase the background. The application is responsible for erasing the background if a window class is created without a background brush. For more information, see the description of the **hbrBackground** member of the [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure.

### `rcPaint`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the upper left and lower right corners of the rectangle in which the painting is requested, in device units relative to the upper-left corner of the client area.

### `fRestore`

Reserved; used internally by the system.

### `fIncUpdate`

Reserved; used internally by the system.

### `rgbReserved`

Reserved; used internally by the system.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[Painting and Drawing Structures](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-structures)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)