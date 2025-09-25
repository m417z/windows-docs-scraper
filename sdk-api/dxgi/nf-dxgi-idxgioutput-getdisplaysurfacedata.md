# IDXGIOutput::GetDisplaySurfaceData

## Description

[Starting with Direct3D 11.1, we recommend not to use **GetDisplaySurfaceData** anymore to retrieve the current display surface. Instead, use [IDXGIOutput1::GetDisplaySurfaceData1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-getdisplaysurfacedata1), which supports stereo display mode.]

Gets a copy of the current display surface.

## Parameters

### `pDestination` [in]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)***

A pointer to a destination surface (see [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

**IDXGIOutput::GetDisplaySurfaceData** can only be called when an output is in full-screen mode. If the method succeeds, DXGI fills the destination surface.

Use [IDXGIOutput::GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-getdesc) to determine the size (width and height) of the output when you want to allocate space for the destination surface. This is true regardless of target monitor rotation. A destination surface created by a graphics component (such as Direct3D 10) must be created with CPU-write permission (see D3D10_CPU_ACCESS_WRITE). Other surfaces should be created with CPU read-write permission (see D3D10_CPU_ACCESS_READ_WRITE). This method will modify the surface data to fit the destination surface (stretch, shrink, convert format, rotate). The stretch and shrink is performed with point-sampling.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)