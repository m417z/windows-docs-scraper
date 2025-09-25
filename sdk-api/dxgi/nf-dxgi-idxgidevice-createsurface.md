# IDXGIDevice::CreateSurface

## Description

Returns a surface. This method is used internally and you should not call it directly in your application.

## Parameters

### `pDesc` [in]

Type: **const [DXGI_SURFACE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_surface_desc)***

A pointer to a [DXGI_SURFACE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_surface_desc) structure that describes the surface.

### `NumSurfaces`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of surfaces to create.

### `Usage`

Type: **[DXGI_USAGE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage)**

A [DXGI_USAGE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage) flag that specifies how the surface is expected to be used.

### `pSharedResource` [in, optional]

Type: **const [DXGI_SHARED_RESOURCE](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_shared_resource)***

An optional pointer to a [DXGI_SHARED_RESOURCE](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_shared_resource) structure that contains shared resource information for opening views of such resources.

### `ppSurface` [out]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)****

The address of an [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface) interface pointer to the first created surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

The **CreateSurface** method creates a buffer to exchange data between one or more devices. It is used internally, and you should not directly call it.

The runtime automatically creates an [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface) interface when it creates a Direct3D resource object that represents a surface. For example, the runtime creates an **IDXGISurface** interface when it calls [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d) or [ID3D10Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createtexture2d) to create a 2D texture. To retrieve the **IDXGISurface** interface that represents the 2D texture surface, call [ID3D11Texture2D::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) or **ID3D10Texture2D::QueryInterface**. In this call, you must pass the identifier of **IDXGISurface**. If the 2D texture has only a single MIP-map level and does not consist of an array of textures, **QueryInterface** succeeds and returns a pointer to the **IDXGISurface** interface pointer. Otherwise, **QueryInterface** fails and does not return the pointer to **IDXGISurface**.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[ID3D10Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createtexture2d)

[ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d)

[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)