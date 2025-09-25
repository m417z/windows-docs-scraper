# D2D1_WINDOW_STATE enumeration

## Description

Describes whether a window is occluded.

## Constants

### `D2D1_WINDOW_STATE_NONE:0x0000000`

The window is not occluded.

### `D2D1_WINDOW_STATE_OCCLUDED:0x0000001`

The window is occluded.

### `D2D1_WINDOW_STATE_FORCE_DWORD:0xffffffff`

## Remarks

If the window was occluded the last time [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) was called, the next time the render target calls [CheckWindowState](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1hwndrendertarget-checkwindowstate), it returns **D2D1_WINDOW_STATE_OCCLUDED** regardless of the current window state. If you want to use **CheckWindowState** to check the current window state, call **CheckWindowState** after every **EndDraw** call and ignore its return value. This will ensure that your next call to **CheckWindowState** state returns the actual window state.

## See also

[CheckWindowState](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1hwndrendertarget-checkwindowstate)