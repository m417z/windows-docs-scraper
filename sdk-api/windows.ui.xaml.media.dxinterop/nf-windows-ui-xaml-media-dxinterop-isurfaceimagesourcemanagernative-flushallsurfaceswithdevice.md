# ISurfaceImageSourceManagerNative::xaml

## Description

Flushes all current GPU work for all [SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource) or [VirtualSurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.virtualsurfaceimagesource) objects associated with the given device.

## Parameters

### `device` [in]

The device that was used to create [SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource) objects in this process. It must be an [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) or an [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **FlushAllSurfacesWithDevice** method flushes current GPU work for all [SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource) objects that were created with *device*. This GPU work includes Direct2D rendering work and internal GPU work done by the framework associated with rendering. This is useful if an application has created multiple **SurfaceImageSource** objects and needs to flush the GPU work for all of these surfaces from the background rendering thread. By flushing this work from the background thread the work can be better parallelized, with work being done on the UI thread to improve performance.

You can call the **FlushAllSurfacesWithDevice** method from a non-UI thread.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)

[ISurfaceImageSourceManagerNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-isurfaceimagesourcemanagernative)

[SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource)

[VirtualSurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.virtualsurfaceimagesource)