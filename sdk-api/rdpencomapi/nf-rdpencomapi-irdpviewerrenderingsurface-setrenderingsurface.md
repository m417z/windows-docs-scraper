# IRDPViewerRenderingSurface::SetRenderingSurface

## Description

[The [IRDPViewerRenderingSurface](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerrenderingsurface) interface is no longer available for use as of Windows 10, version 1709.]

Sets the rendering surface to be used by the viewer.

## Parameters

### `pRenderingSurface` [in]

The address of the [SurfaceImageSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.media.imaging.surfaceimagesource) object to use for the rendering surface.

### `surfaceWidth` [in]

The width, in pixels, of the rendering surface.

### `surfaceHeight` [in]

The height, in pixels, of the rendering surface.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPViewerRenderingSurface](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerrenderingsurface)