# ID2D1Bitmap1::GetSurface

## Description

Gets either the surface that was specified when the bitmap was created, or the default surface created when the bitmap was created.

## Parameters

### `dxgiSurface` [out, optional]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)****

The underlying DXGI surface for the bitmap.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| D2DERR_BITMAP_BOUND_AS_TARGET | Cannot draw with a bitmap that is currently bound as the target bitmap. |

## Remarks

The bitmap used must have been created from a DXGI surface render target, a derived render target, or a device context created from an [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device).

The returned surface can be used with Microsoft Direct3D or any other API that interoperates with shared surfaces. The application must transitively ensure that the surface is usable on the Direct3D device that is used in this context. For example, if using the surface with Direct2D then the Direct2D render target must have been created through [ID2D1Factory::CreateDxgiSurfaceRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createdxgisurfacerendertarget(idxgisurface_constd2d1_render_target_properties_id2d1rendertarget)) or on a device context created on the same device.

## See also

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))

[ID2D1DeviceContext::CreateBitmapFromDxgiSurface](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmapfromdxgisurface(idxgisurface_constd2d1_bitmap_properties1__id2d1bitmap1))

[ID2D1RenderTarget::CreateSharedBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-createsharedbitmap)