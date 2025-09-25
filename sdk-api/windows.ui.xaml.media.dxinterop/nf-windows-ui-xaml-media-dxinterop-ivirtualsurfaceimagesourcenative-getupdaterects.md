# IVirtualSurfaceImageSourceNative::GetUpdateRects (windows.ui.xaml.media.dxinterop.h)

## Description

Gets the set of regions that must be updated on the shared surface.

## Parameters

### `updates` [in]

The number of regions that must be updated. You obtain this by calling [GetUpdateRectCount](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nf-windows-ui-xaml-media-dxinterop-ivirtualsurfaceimagesourcenative-getupdaterectcount).

### `count` [out]

Receives a list of regions that must be updated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[IVirtualSurfaceImageSourceNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-ivirtualsurfaceimagesourcenative)