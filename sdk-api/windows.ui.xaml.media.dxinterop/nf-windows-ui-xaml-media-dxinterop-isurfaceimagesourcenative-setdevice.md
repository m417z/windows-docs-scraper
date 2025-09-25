# ISurfaceImageSourceNative::SetDevice (windows.ui.xaml.media.dxinterop.h)

## Description

Sets the DXGI device, created with D3D11_CREATE_DEVICE_BGRA_SUPPORT, that will draw the surface. This method must be called from the UI thread.

## Parameters

### `device` [in]

Pointer to the DXGI device interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DirectX and XAML interop](https://learn.microsoft.com/previous-versions/windows/apps/hh825871(v=win.10))

[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)

[ISurfaceImageSourceNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-isurfaceimagesourcenative)