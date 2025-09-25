## Description

Copy a multi-sampled resource into a non-multi-sampled resource.

## Parameters

### `pDstResource`

Type: [in] **ID3D12Resource***

Destination resource. Must be a created on a [D3D12_HEAP_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type) heap and be single-sampled. See [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource).

### `DstSubresource`

Type: [in] **UINT**

A zero-based index, that identifies the destination subresource. Use [D3D12CalcSubresource](https://learn.microsoft.com/windows/win32/direct3d12/d3d12calcsubresource) to calculate the subresource index if the parent resource is complex.

### `pSrcResource`

Type: [in] **ID3D12Resource***

Source resource. Must be multisampled.

### `SrcSubresource`

Type: [in] **UINT**

The source subresource of the source resource.

### `Format`

Type: [in] **DXGI_FORMAT**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) that indicates how the multisampled resource will be resolved to a single-sampled resource. See remarks.

## Remarks

### Debug layer

The debug layer will issue an error if the subresources referenced by the source view is not in the [D3D12_RESOURCE_STATE_RESOLVE_SOURCE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) state.

The debug layer will issue an error if the destination buffer is not in the [D3D12_RESOURCE_STATE_RESOLVE_DEST](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) state.

The source and destination resources must be the same resource type and have the same dimensions. In addition, they must have compatible formats. There are three scenarios for this:

| Scenario | Requirements |
| --- | --- |
| Source and destination are prestructured and typed | Both the source and destination must have identical formats and that format must be specified in the Format parameter. |
| One resource is prestructured and typed and the other is prestructured and typeless | The typed resource must have a format that is compatible with the typeless resource (i.e. the typed resource is DXGI_FORMAT_R32_FLOAT and the typeless resource is DXGI_FORMAT_R32_TYPELESS). The format of the typed resource must be specified in the Format parameter. |
| Source and destination are prestructured and typeless | Both the source and destination must have the same typeless format (i.e. both must have DXGI_FORMAT_R32_TYPELESS), and the Format parameter must specify a format that is compatible with the source and destination (i.e. if both are DXGI_FORMAT_R32_TYPELESS then DXGI_FORMAT_R32_FLOAT could be specified in the Format parameter). For example, given the DXGI_FORMAT_R16G16B16A16_TYPELESS format:<br><br>* The source (or dest) format could be DXGI_FORMAT_R16G16B16A16_UNORM<br>* The dest (or source) format could be DXGI_FORMAT_R16G16B16A16_FLOAT |

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist)

[Subresources](https://learn.microsoft.com/windows/win32/direct3d12/subresources)