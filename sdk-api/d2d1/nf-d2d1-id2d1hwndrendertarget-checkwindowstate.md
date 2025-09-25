# ID2D1HwndRenderTarget::CheckWindowState

## Description

Indicates whether the HWND associated with this render target is occluded.

## Return value

Type: **[D2D1_WINDOW_STATE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_window_state)**

A value that indicates whether the HWND associated with this render target is occluded.

## Remarks

**Note** If the window was occluded the last time that [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) was called, the next time that the render target calls **CheckWindowState**, it will return [D2D1_WINDOW_STATE_OCCLUDED](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_window_state) regardless of the current window state. If you want to use **CheckWindowState** to determine the current window state, you should call **CheckWindowState** after every **EndDraw** call and ignore its return value. This call will ensure that your next call to **CheckWindowState** state will return the actual window state.

## See also

[ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget)