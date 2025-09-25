# ID2D1RenderTarget::IsSupported

## Description

Indicates whether the render target supports the specified properties.

## Parameters

### `renderTargetProperties` [in]

Type: **const [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties)***

The render target properties to test.

## Return value

Type: **BOOL**

**TRUE** if the specified render target properties are supported by this render target; otherwise, **FALSE**.

## Remarks

This method does not evaluate the DPI settings specified by the *renderTargetProperties* parameter.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)