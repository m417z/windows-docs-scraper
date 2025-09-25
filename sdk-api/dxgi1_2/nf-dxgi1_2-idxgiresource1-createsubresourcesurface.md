# IDXGIResource1::CreateSubresourceSurface

## Description

Creates a subresource surface object.

## Parameters

### `index`

The index of the subresource surface object to enumerate.

### `ppSurface` [out]

The address of a pointer to a [IDXGISurface2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgisurface2) interface that represents the created subresource surface object at the position specified by the *index* parameter.

## Return value

Returns S_OK if successful; otherwise, returns one of the following values:

* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the index is out of range or if the subresource is not a valid surface.
* E_OUTOFMEMORY if insufficient memory is available to create the subresource surface object.

A subresource is a valid surface if the original resource would have been a valid surface had its array size been equal to 1.

## Remarks

Subresource surface objects implement the [IDXGISurface2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgisurface2) interface, which inherits from [IDXGISurface1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface1) and indirectly [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface). Therefore, the GDI-interoperable methods of **IDXGISurface1** work if the original resource interface object was created with the GDI-interoperable flag ([D3D11_RESOURCE_MISC_GDI_COMPATIBLE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag)).

**CreateSubresourceSurface** creates a subresource surface that is based on the resource interface on which **CreateSubresourceSurface** is called. For example, if the original resource interface object is a 2D texture, the created subresource surface is also a 2D texture.

You can use **CreateSubresourceSurface** to create parts of a stereo resource so you can use Direct2D on either the left or right part of the stereo resource.

## See also

[IDXGIResource1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiresource1)