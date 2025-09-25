# IDXGIOutput1::GetDisplaySurfaceData1

## Description

Copies the display surface (front buffer) to a user-provided resource.

## Parameters

### `pDestination` [in]

A pointer to a resource interface that represents the resource to which **GetDisplaySurfaceData1** copies the display surface.

## Return value

Returns one of the error codes described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

**GetDisplaySurfaceData1** is similar to [IDXGIOutput::GetDisplaySurfaceData](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-getdisplaysurfacedata) except **GetDisplaySurfaceData1** takes an [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) and **IDXGIOutput::GetDisplaySurfaceData** takes an [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface).

**GetDisplaySurfaceData1** returns an error if the input resource is not a 2D texture (represented by the [ID3D11Texture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11texture2d) interface) with an array size (**ArraySize** member of the [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc) structure) that is equal to the swap chain buffers.

The original [IDXGIOutput::GetDisplaySurfaceData](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-getdisplaysurfacedata) and the updated **GetDisplaySurfaceData1** behave exactly the same. **GetDisplaySurfaceData1** was required because textures with an array size equal to 2 (**ArraySize** = 2) do not implement [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface).

You can call **GetDisplaySurfaceData1** only when an output is in full-screen mode. If **GetDisplaySurfaceData1** succeeds, it fills the destination resource.

Use [IDXGIOutput::GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-getdesc) to determine the size (width and height) of the output when you want to allocate space for the destination resource. This is true regardless of target monitor rotation. A destination resource created by a graphics component (such as Direct3D 11) must be created with CPU write permission (see [D3D11_CPU_ACCESS_WRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag)). Other surfaces can be created with CPU read-write permission (**D3D11_CPU_ACCESS_READ** | **D3D11_CPU_ACCESS_WRITE**). **GetDisplaySurfaceData1** modifies the surface data to fit the destination resource (stretch, shrink, convert format, rotate). **GetDisplaySurfaceData1** performs the stretch and shrink with point sampling.

## See also

[IDXGIOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutput1)