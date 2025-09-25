# IVirtualSurfaceImageSourceNative::RegisterForUpdatesNeeded (windows.ui.xaml.media.dxinterop.h)

## Description

Registers for the callback that will perform the drawing when an update to the shared surface is requested.

## Parameters

### `callback` [in]

Pointer to an implementation of [IVirtualSurfaceUpdatesCallbackNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-ivirtualsurfaceupdatescallbacknative).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[IVirtualSurfaceImageSourceNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-ivirtualsurfaceimagesourcenative)

[IVirtualSurfaceUpdatesCallbackNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-ivirtualsurfaceupdatescallbacknative)