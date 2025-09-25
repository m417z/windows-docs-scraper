# ISurfaceImageSourceNativeWithD2D::BeginDraw (windows.ui.xaml.media.dxinterop.h)

## Description

Initiates an update to the associated [SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource) or [VirtualSurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.virtualsurfaceimagesource).

## Parameters

### `updateRect` [in]

The region of the surface that will be drawn into.

### `iid` [in]

IID used to lookup the object for drawing.

### `updateObject` [out]

Receives a COM pointer to the drawing object. Based on *iid*, this may be either an [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface), when not using batched drawing, or a shared [ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext), when using batched Direct2D drawing to improve performance when updating Direct2D content across multiple surfaces.

### `offset` [out]

Receives the point (x,y) offset of the surface that will be drawn into.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[ISurfaceImageSourceNativeWithD2D](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-isurfaceimagesourcenativewithd2d)

[SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource)

[VirtualSurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.virtualsurfaceimagesource)