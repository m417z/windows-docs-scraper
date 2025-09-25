# ID2D1DeviceContext::GetTarget

## Description

Gets the target currently associated with the device context.

## Parameters

### `image` [out, optional]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)****

When this method returns, contains the address of a pointer to the target currently associated with the device context.

## Remarks

If a target is not associated with the device context, *target* will contain **NULL** when the methods returns.

If the currently selected target is a bitmap rather than a command list, the application can gain access to the initial bitmaps created by using one of the following methods:

* [CreateHwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createhwndrendertarget(constd2d1_render_target_properties_constd2d1_hwnd_render_target_properties_id2d1hwndrendertarget))
* [CreateDxgiSurfaceRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createdxgisurfacerendertarget(idxgisurface_constd2d1_render_target_properties_id2d1rendertarget))
* [CreateWicBitmapRenderTarget](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1factory-createwicbitmaprendertarget)
* [CreateDCRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1factory-createdcrendertarget)
* [CreateCompatibleRenderTarget](https://learn.microsoft.com/windows/win32/direct2d/id2d1rendertarget-createcompatiblerendertarget)

It is not possible for an application to destroy these bitmaps. All of these bitmaps are bindable as bitmap targets. However not all of these bitmaps can be used as bitmap sources for [ID2D1RenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1rendertarget) methods.

[CreateDxgiSurfaceRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createdxgisurfacerendertarget(idxgisurface_constd2d1_render_target_properties_id2d1rendertarget)) will create a bitmap that is usable as a bitmap source if the DXGI surface is bindable as a shader resource view.

[CreateCompatibleRenderTarget](https://learn.microsoft.com/windows/win32/direct2d/id2d1rendertarget-createcompatiblerendertarget) will always create bitmaps that are usable as a bitmap source.

[ID2D1RenderTarget::BeginDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-begindraw) will copy from the HDC to the original bitmap associated with it. [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) will copy from the original bitmap to the HDC.

[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) objects will be locked in the following circumstances:

* BeginDraw has been called and the currently selected target bitmap is a WIC bitmap.
* A WIC bitmap is set as the target of a device context after BeginDraw has been called and before EndDraw has been called.
* Any of the ID2D1Bitmap::Copy* methods are called with a WIC bitmap as either the source or destination.

IWICBitmap objects will be unlocked in the following circumstances:

* EndDraw is called and the currently selected target bitmap is a WIC bitmap.
* A WIC bitmap is removed as the target of a device context between the calls to BeginDraw and EndDraw.
* Any of the ID2D1Bitmap::Copy* methods are called with a WIC bitmap as either the source or destination.

Direct2D will only lock bitmaps that are not currently locked.

Calling [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for [ID2D1GdiInteropRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1gdiinteroprendertarget) will always succeed. [ID2D1GdiInteropRenderTarget::GetDC](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1gdiinteroprendertarget-getdc) will return a device context corresponding to the currently bound target bitmap. GetDC will fail if the target bitmap was not created with the GDI_COMPATIBLE flag set.

[ID2D1HwndRenderTarget::Resize](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1hwndrendertarget-resize(constd2d1_size_u)) will return **DXGI_ERROR_INVALID_CALL** if there are any outstanding references to the original target bitmap associated with the render target.

Although the target can be a command list, it cannot be any other type of image. It cannot be the output image of an effect.

## See also

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))

[ID2D1DeviceContext::SetTarget](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-settarget)