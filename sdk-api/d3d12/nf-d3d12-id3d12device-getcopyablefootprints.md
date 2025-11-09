# ID3D12Device::GetCopyableFootprints

## Description

Gets a resource layout that can be copied.
Helps the app fill-in
[D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) and
[D3D12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_footprint) when suballocating space in upload heaps.

## Parameters

### `pResourceDesc` [in]

Type: **const [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc)***

A description of the resource, as a pointer to a [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc) structure.

### `FirstSubresource` [in]

Type: **UINT**

Index of the first subresource in the resource.
The range of valid values is 0 to D3D12_REQ_SUBRESOURCES.

### `NumSubresources` [in]

Type: **UINT**

The number of subresources in the resource. The range of valid values is 0 to (D3D12_REQ_SUBRESOURCES - *FirstSubresource*).

### `BaseOffset`

Type: **UINT64**

The offset, in bytes, that is added to the *Offset* of each [D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) in the *pLayouts *array.

### `pLayouts` [out, optional]

Type: **[D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint)***

A pointer to an array (of length *NumSubresources*) of
[D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) structures, to be filled with the description and placement of each subresource.

### `pNumRows` [out, optional]

Type: **UINT***

A pointer to an array (of length *NumSubresources*) of integer variables, to be filled with the number of rows for each subresource.

### `pRowSizeInBytes` [out, optional]

Type: **UINT64***

A pointer to an array (of length *NumSubresources*) of integer variables, each entry to be filled with the unpadded size in bytes of a row, of each subresource.

For example, if a Texture2D resource has a width of 32 and bytes per pixel of 4,

then *pRowSizeInBytes* returns 128.

*pRowSizeInBytes* should not be confused with **row pitch**, as examining *pLayouts* and getting the row pitch from that will give you 256 as it is aligned to D3D12_TEXTURE_DATA_PITCH_ALIGNMENT.

### `pTotalBytes` [out, optional]

Type: **UINT64***

A pointer to an integer variable, to be filled with the total size, in bytes. If *pResourceDesc* is invalid, then the value of *pTotalBytes* is set to **UINT64_MAX**.

## Remarks

This routine assists the application in filling out
[D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) and
[D3D12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_footprint) structures, when suballocating space in upload heaps.
The resulting structures are GPU adapter-agnostic, meaning that the values will not vary from one GPU adapter to the next.
**GetCopyableFootprints** uses specified details about resource formats, texture layouts, and alignment requirements (from the [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc) structure) to fill out the subresource structures.
Applications have access to all these details, so this method, or a variation of it, could be written as part of the app.

#### Examples

The [D3D12Multithreading](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Device::GetCopyableFootprints** as follows:

```cpp
// Returns required size of a buffer to be used for data upload
inline UINT64 GetRequiredIntermediateSize(
    _In_ ID3D12Resource* pDestinationResource,
    _In_range_(0,D3D12_REQ_SUBRESOURCES) UINT FirstSubresource,
    _In_range_(0,D3D12_REQ_SUBRESOURCES-FirstSubresource) UINT NumSubresources)
{
    D3D12_RESOURCE_DESC Desc = pDestinationResource->GetDesc();
    UINT64 RequiredSize = 0;

    ID3D12Device* pDevice;
    pDestinationResource->GetDevice(__uuidof(*pDevice), reinterpret_cast<void**>(&pDevice));
    pDevice->GetCopyableFootprints(&Desc, FirstSubresource, NumSubresources, 0, nullptr, nullptr, nullptr, &RequiredSize);
    pDevice->Release();

    return RequiredSize;
}

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[CD3DX12_RESOURCE_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-resource-desc)

[CD3DX12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-subresource-footprint)

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)**