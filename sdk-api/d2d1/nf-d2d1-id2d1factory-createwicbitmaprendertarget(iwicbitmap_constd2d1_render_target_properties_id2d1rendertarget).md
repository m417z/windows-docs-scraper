# ID2D1Factory::CreateWicBitmapRenderTarget

## Description

Creates a render target that renders to a Microsoft Windows Imaging Component (WIC) bitmap.

## Parameters

### `target` [in]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmap)***

The bitmap that receives the rendering output of the render target.

### `renderTargetProperties` [in]

Type: **const [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties)***

The rendering mode, pixel format, remoting options, DPI information, and the minimum DirectX support required for hardware rendering. For information about supported pixel formats, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

### `renderTarget` [out]

Type: **[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)****

When this method returns, contains the address of the pointer to the [ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget) object created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

You must use [D2D1_FEATURE_LEVEL_DEFAULT](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_feature_level) for the **minLevel** member of the *renderTargetProperties* parameter with this method.

Your application should create render targets once and hold onto them for the life of the application or until the [D2DERR_RECREATE_TARGET](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-error-codes) error is received. When you receive this error, you need to recreate the render target (and any resources it created).

> [!NOTE]
> This method isn't supported on Windows Phone and will fail when called on a device with error code 0x8899000b (“There is no hardware rendering device available for this operation”). Because the Windows Phone Emulator supports WARP rendering, this method will fail when called on the emulator with a different error code, 0x88982f80 (wincodec_err_unsupportedpixelformat).

## See also

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)