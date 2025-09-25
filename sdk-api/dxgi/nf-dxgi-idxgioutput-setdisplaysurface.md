# IDXGIOutput::SetDisplaySurface

## Description

Changes the display mode.

## Parameters

### `pScanoutSurface` [in]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)***

A pointer to a surface (see [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)) used for rendering an image to the screen. The surface must have been created as a back buffer (DXGI_USAGE_BACKBUFFER).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

**IDXGIOutput::SetDisplaySurface** should not be called directly by applications, since results will be unpredictable. It is called implicitly by the DXGI swap chain object during full-screen transitions, and should not be used as a substitute for swap-chain methods.

This method should only be called between [IDXGIOutput::TakeOwnership](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-takeownership) and [IDXGIOutput::ReleaseOwnership](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-releaseownership) calls.

### Notes for Windows Store apps

If a Windows Store app uses **SetDisplaySurface**, it fails with [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)