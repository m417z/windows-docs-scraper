## Description

The **CreateDirect3D12BackBufferResource** method creates a Direct3D 12 resource for use as a back buffer for the corresponding [HolographicCamera](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographiccamera) API object.

The [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc) structure can contain any set of valid initial values. Any values that won't work with this [HolographicCamera](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographiccamera) will be overridden in the struct indicated by *pTexture2DDesc*, which is not an optional parameter. The resource is created so that it is already committed to a heap.

## Parameters

### `pDevice`

Type: **[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)\***

A Direct3D 12 device, which will be used to create the resource.

### `pTexture2DDesc`

Type: **[D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc)\***

The Direct3D 12 resource description. This parameter is not optional.

**CreateDirect3D12BackBufferResource** adjusts the description as needed to comply with platform requirements, such as buffer size or format restrictions, which are determined at runtime. Your application should inspect the descriptor for the texture returned in *ppCreatedTexture2DResource*, and respond appropriately to any differences from what was specified.

### `ppCreatedTexture2DResource`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\*\***

If successful, the Direct3D 12 2D texture resource for use as a content buffer. Otherwise, `nullptr`.

## Return value

**S_OK** if successful, otherwise returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) error code indicating the reason for failure. Also see [COM Error Codes (UI, Audio, DirectX, Codec)](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## See also