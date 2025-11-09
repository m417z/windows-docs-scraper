## Description

Gets a resource layout that can be copied. Helps your app fill in [D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) and [D3D12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_subresource_footprint) when suballocating space in upload heaps.

## Parameters

### `pResourceDesc`

Type: **const [D3D12_RESOURCE_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc1)***

A description of the resource, as a pointer to a **D3D12_RESOURCE_DESC1** structure.

### `FirstSubresource`

Type: [in] **UINT**

Index of the first subresource in the resource. The range of valid values is 0 to D3D12_REQ_SUBRESOURCES.

### `NumSubresources`

Type: [in] **UINT**

The number of subresources in the resource. The range of valid values is 0 to (D3D12_REQ_SUBRESOURCES - *FirstSubresource*).

### `BaseOffset`

Type: **UINT64**

The offset, in bytes, that is added to the *Offset* of each [D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) in the *pLayouts *array.

### `pLayouts`

Type: [out, optional] **[D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint)***

A pointer to an array (of length *NumSubresources*) of [D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) structures, to be filled with the description and placement of each subresource.

### `pNumRows`

Type: [out, optional] **UINT***

A pointer to an array (of length *NumSubresources*) of integer variables, to be filled with the number of rows for each subresource.

### `pRowSizeInBytes`

Type: [out, optional] **UINT64***

A pointer to an array (of length *NumSubresources*) of integer variables, each entry to be filled with the unpadded size in bytes of a row, of each subresource.

For example, if a Texture2D resource has a width of 32 and bytes per pixel of 4, then *pRowSizeInBytes* returns 128.

*pRowSizeInBytes* should not be confused with **row pitch**, as examining *pLayouts* and getting the row pitch from that will give you 256 as it is aligned to D3D12_TEXTURE_DATA_PITCH_ALIGNMENT.

### `pTotalBytes`

Type: [out, optional] **UINT64***

A pointer to an integer variable, to be filled with the total size, in bytes. If *pResourceDesc* is invalid, then the value of *pTotalBytes* is set to **UINT64_MAX**.

## Remarks

For remarks and examples, see [ID3D12Device::GetCopyableFootprints](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getcopyablefootprints).

## See also

* [CD3DX12_RESOURCE_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-resource-desc)

* [CD3DX12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-subresource-footprint)

* [ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)

* [Sampler feedback specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html)**