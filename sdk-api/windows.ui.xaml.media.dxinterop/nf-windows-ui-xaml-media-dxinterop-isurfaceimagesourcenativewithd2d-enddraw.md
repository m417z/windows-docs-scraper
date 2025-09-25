# ISurfaceImageSourceNativeWithD2D::EndDraw (windows.ui.xaml.media.dxinterop.h)

## Description

Closes the surface draw operation.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Always call the **EndDraw** method on the UI thread in order to synchronize updating the Microsoft DirectX content with the current XAML UI thread frame.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[ISurfaceImageSourceNativeWithD2D](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-isurfaceimagesourcenativewithd2d)

[SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource)

[VirtualSurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.virtualsurfaceimagesource)