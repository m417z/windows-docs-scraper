# D2D1_HWND_RENDER_TARGET_PROPERTIES structure

## Description

Contains the HWND, pixel size, and presentation options for an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget).

## Members

### `hwnd`

Type: **HWND**

The HWND to which the render target issues the output from its drawing commands.

### `pixelSize`

Type: **[D2D1_SIZE_U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-u)**

The size of the render target, in pixels.

### `presentOptions`

Type: **[D2D1_PRESENT_OPTIONS](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_present_options)**

A value that specifies whether the render target retains the frame after it is presented and whether the render target waits for the device to refresh before presenting.

## Remarks

Use this structure when you call the [CreateHwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createhwndrendertarget(constd2d1_render_target_properties_constd2d1_hwnd_render_target_properties_id2d1hwndrendertarget)) method to create a new [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget).

For convenience, Direct2D provides the [D2D1::HwndRenderTargetProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-hwndrendertargetproperties) function for creating new **D2D1_HWND_RENDER_TARGET_PROPERTIES** structures.

## Examples

The following example uses the [CreateHwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createhwndrendertarget(constd2d1_render_target_properties_constd2d1_hwnd_render_target_properties_id2d1hwndrendertarget)) method to create an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget). It uses the [D2D1::HwndRenderTargetProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-hwndrendertargetproperties) helper function to create a **D2D1_HWND_RENDER_TARGET_PROPERTIES** structure that contains a handle to a window and the size of the drawing area. Because a [D2D1_PRESENT_OPTIONS](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_present_options) value isn't specified, the function uses the default value, **D2D1_PRESENT_OPTIONS_NONE**.

```cpp
RECT rc;
GetClientRect(m_hwnd, &rc);

D2D1_SIZE_U size = D2D1::SizeU(
    rc.right - rc.left,
    rc.bottom - rc.top
    );

// Create a Direct2D render target.
hr = m_pD2DFactory->CreateHwndRenderTarget(
    D2D1::RenderTargetProperties(),
    D2D1::HwndRenderTargetProperties(m_hwnd, size),
    &m_pRenderTarget
    );

```

Code has been omitted from this example.

## See also

[ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget)