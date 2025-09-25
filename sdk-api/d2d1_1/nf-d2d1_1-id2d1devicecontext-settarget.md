# ID2D1DeviceContext::SetTarget

## Description

The bitmap or command list to which the [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) device context will now render.

## Parameters

### `image` [in, optional]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The surface or command list to which the Direct2D device context will render.

## Remarks

The target can be changed at any time, including while the context is drawing.

The target can be either a bitmap created with the [D2D1_BITMAP_OPTIONS_TARGET](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_bitmap_options) flag, or it can be a command list. Other kinds of images cannot be set as a target. For example, you cannot set the output of an effect as target. If the target is not valid the context will enter the **D2DERR_INVALID_TARGET**  error state.

You cannot use **SetTarget** to render to a bitmap/command list from multiple device contexts simultaneously. An image is considered “being rendered to” if it has ever been set on a device context within a [BeginDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-begindraw)/[EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) timespan. If an attempt is made to render to an image through multiple device contexts, all subsequent device contexts after the first will enter an error state.

Callers wishing to attach an image to a second device context should first call [EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) on the first device context.

Here is an example of the correct calling order.

```cpp
pDC1->BeginDraw();
pDC1->SetTarget(pImage);
// …
pDC1->EndDraw();

pDC2->BeginDraw();
pDC2->SetTarget(pImage);
// …
pDC2->EndDraw();

```

Here is an example of the incorrect calling order.

```cpp
pDC1->BeginDraw();
pDC2->BeginDraw();

pDC1->SetTarget(pImage);

// ...

pDC1->SetTarget(NULL);

pDC2->SetTarget(pImage); // This call is invalid, even though pImage is no longer set on pDC1.

// ...

pDC1->EndDraw(); // This EndDraw SUCCEEDs.
pDC2->EndDraw(); // This EndDraw FAILs

```

**Note** Changing the target does not change the bitmap that an HWND render target presents from, nor does it change the bitmap that a DC render target blts to/from.

This API makes it easy for an application to use a bitmap as a source (like in [DrawBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandsink-drawbitmap)) and as a destination at the same time. Attempting to use a bitmap as a source on the same device context to which it is bound as a target will put the device context into the D2DERR_BITMAP_BOUND_AS_TARGET error state.

It is acceptable to have a bitmap bound as a target bitmap on multiple render targets at once. Applications that do this must properly synchronize rendering with [Flush](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-flush) or [EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw).

You can change the target at any time, including while the context is drawing.

You can set the target to NULL, in which case drawing calls will put the device context into an error state with D2DERR_WRONG_STATE. Calling **SetTarget** with a NULL target does not restore the original target bitmap to the device context.

If the device context has an outstanding HDC, the context will enter the **D2DERR_WRONG_STATE** error state. The target will not be changed.

If the bitmap and the device context are not in the same resource domain, the context will enter **\\** error state. The target will not be changed.

[ID2D1RenderTarget::GetPixelSize](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-getpixelsize) returns the size of the current target bitmap (or 0, 0) if there is no bitmap bound).
[ID2D1RenderTarget::GetSize](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-getsize) returns the pixel size of the current bitmap scaled by the DPI of the render target.
**SetTarget** does not affect the DPI of the render target.

[ID2D1RenderTarget::GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-getpixelformat) returns the pixel format of the current target bitmap (or [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), [D2D1_ALPHA_MODE_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode) if there is none).

[ID2D1Bitmap::CopyFromRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1bitmap-copyfromrendertarget) copies from the currently bound target bitmap.

## See also

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))

[ID2D1DeviceContext::GetTarget](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-gettarget)