# ISurfaceImageSourceNativeWithD2D::SetDevice (windows.ui.xaml.media.dxinterop.h)

## Description

Sets the Microsoft DirectX Graphics Infrastructure (DXGI) or Direct2D device, created with **D3D11_CREATE_DEVICE_BGRA_SUPPORT**, that will draw the surface.

## Parameters

### `device` [in]

Pointer to the DXGI device interface. You can pass an [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device) to signal that this surface participates in Direct2D batching to improve performance when updating Direct2D content across multiple surfaces. The device must have multithreading supported enabled if the app draws to the surface from a background thread.

## Return value

This method fails when the SurfaceImageSource is larger than the maximum texture size supported by the Direct3D device. Apps should use VirtualSurfaceImageSource for surfaces larger than the maximum texture size supported by the Direct3D device.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[ISurfaceImageSourceNativeWithD2D](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-isurfaceimagesourcenativewithd2d)

[SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource)

[VirtualSurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.virtualsurfaceimagesource)