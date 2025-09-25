# HwndRenderTargetProperties function

## Description

Creates a [D2D1_HWND_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_hwnd_render_target_properties) structure.

## Parameters

### `hwnd` [in]

Type: **HWND**

The HWND to which the render target issues the output from its drawing commands.

### `pixelSize` [in]

Type: **[D2D1_SIZE_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-u)**

The size of the render target, in pixels. The default value is a [D2D1_SIZE_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-u) that has a width and height of 0.

### `presentOptions` [in]

Type: **[D2D1_PRESENT_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_present_options)**

A value that specifies whether the render target retains the frame after it is presented and whether the render target waits for the device to refresh before presenting. The default value is [D2D1_PRESENT_OPTIONS_NONE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_present_options).

## Return value

Type: **[D2D1_HWND_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_hwnd_render_target_properties)**

A structure that contains the HWND, pixel size, and presentation options for an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1hwndrendertarget).