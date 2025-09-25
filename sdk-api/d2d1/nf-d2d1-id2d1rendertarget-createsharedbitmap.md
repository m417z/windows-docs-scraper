# ID2D1RenderTarget::CreateSharedBitmap

## Description

Creates an [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap) whose data is shared with another resource.

## Parameters

### `riid`

Type: **REFIID**

The interface ID of the object supplying the source data.

### `data` [in, out]

Type: **void***

An [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap), [IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface), or an [IWICBitmapLock](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmaplock) that contains the data to share with the new **ID2D1Bitmap**. For more information, see the Remarks section.

### `bitmapProperties` [in, optional]

Type: **[D2D1_BITMAP_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_bitmap_properties)***

The pixel format and DPI of the bitmap to create . The [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) portion of the pixel format must match the [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) of *data* or the method will fail, but the alpha modes don't have to match. To prevent a mismatch, you can pass **NULL** or the value obtained from the [D2D1::PixelFormat](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-pixelformat) helper function. The DPI settings do not have to match those of *data*. If both *dpiX* and *dpiY* are 0.0f, the DPI of the render target is used.

### `bitmap` [out]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)****

When this method returns, contains the address of a pointer to the new bitmap. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The **CreateSharedBitmap** method is useful for efficiently reusing bitmap data and can also be used to provide interoperability with Direct3D.

### Sharing an ID2D1Bitmap

By passing an [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap) created by a render target that is resource-compatible, you can share a bitmap with that render target; both the original **ID2D1Bitmap** and the new **ID2D1Bitmap** created by this method will point to the same bitmap data. For more information about when render target resources can be shared, see the Sharing Render Target Resources section of the [Resources Overview](https://learn.microsoft.com/windows/win32/Direct2D/resources-and-resource-domains).

You may also use this method to reinterpret the data of an existing bitmap and specify a new DPI or alpha mode. For example, in the case of a bitmap atlas, an [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap) may contain multiple sub-images, each of which should be rendered with a different [D2D1_ALPHA_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-d2d1_alpha_mode) (**D2D1_ALPHA_MODE_PREMULTIPLIED** or **D2D1_ALPHA_MODE_IGNORE**). You could use the **CreateSharedBitmap** method to reinterpret the bitmap using the desired alpha mode without having to load a separate copy of the bitmap into memory.

### Sharing an IDXGISurface

When using a DXGI surface render target (an [ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget) object created by the [CreateDxgiSurfaceRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createdxgisurfacerendertarget(idxgisurface_constd2d1_render_target_properties_id2d1rendertarget)) method), you can pass an [IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface) surface to the **CreateSharedBitmap** method to share video memory with Direct3D and manipulate Direct3D content as an [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap). As described in the [Resources Overview](https://learn.microsoft.com/windows/win32/Direct2D/resources-and-resource-domains), the render target and the [IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface) must be using the same Direct3D device.

Note also that the [IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface) must use one of the supported pixel formats and alpha modes described in [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

For more information about interoperability with Direct3D, see the [Direct2D and Direct3D Interoperability Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-and-direct3d-interoperation-overview).

### Sharing an IWICBitmapLock

An [IWICBitmapLock](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmaplock) stores the content of a WIC bitmap and shields it from simultaneous accesses. By passing an **IWICBitmapLock** to the **CreateSharedBitmap** method, you can create an [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap) that points to the bitmap data already stored in the **IWICBitmapLock**.

To use an [IWICBitmapLock](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmaplock) with the **CreateSharedBitmap** method, the render target must use software rendering. To force a render target to use software rendering, set to [D2D1_RENDER_TARGET_TYPE_SOFTWARE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_render_target_type) the **type** field of the [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties) structure that you use to create the render target. To check whether an existing render target uses software rendering, use the [IsSupported](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-issupported(constd2d1_render_target_properties_)) method.

## See also

[Direct2D and Direct3D Interoperability Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-and-direct3d-interoperation-overview)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface)

[IWICBitmapLock](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmaplock)

[Resources Overview](https://learn.microsoft.com/windows/win32/Direct2D/resources-and-resource-domains)

[Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes)