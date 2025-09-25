# ISurfaceImageSourceNative::BeginDraw (windows.ui.xaml.media.dxinterop.h)

## Description

Opens the supplied DXGI surface for drawing.

## Parameters

### `updateRect` [in]

The region of the surface that will be drawn into.

### `surface` [out]

Receives a pointer to the surface for drawing.

### `offset` [out]

Receives the point (x,y) offset of the surface that will be drawn into.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the app window that contains the [SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource) isn't active, like when it's suspended, calling the **BeginDraw** method returns an error.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)

[ISurfaceImageSourceNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-isurfaceimagesourcenative)