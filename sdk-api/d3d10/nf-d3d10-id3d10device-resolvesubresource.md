# ID3D10Device::ResolveSubresource

## Description

Copy a multisampled resource into a non-multisampled resource. This API is most useful when re-using the resulting rendertarget of one render pass as an input to a second render pass.

## Parameters

### `pDstResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

Destination resource. Must be a created with the [D3D10_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage) flag and be single-sampled. See [ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource).

### `DstSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index, that identifies the destination subresource. See [D3D10CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-d3d10calcsubresource) for more details.

### `pSrcResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

Source resource. Must be multisampled.

### `SrcSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The source subresource of the source resource.

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) that indicates how the multisampled resource will be resolved to a single-sampled resource. See remarks.

## Remarks

Both the source and destination resources must be the same [resource type](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) and have the same dimensions.

The source and destination must have compatible formats. There are three scenarios for this:

| Scenario | Requirements |
| --- | --- |
| Source and destination are prestructured and typed | Both the source and destination must have identical formats and that format must be specified in the Format parameter. |
| One resource is prestructured and typed and the other is prestructured and typeless | The typed resource must have a format that is compatible with the typeless resource (i.e. the typed resource is DXGI_FORMAT_R32_FLOAT and the typeless resource is DXGI_FORMAT_R32_TYPELESS). The format of the typed resource must be specified in the Format parameter. |
| Source and destination are prestructured and typeless | Both the source and destination must have the same typeless format (i.e. both must have DXGI_FORMAT_R32_TYPELESS), and the Format parameter must specify a format that is compatible with the source and destination (i.e. if both are DXGI_FORMAT_R32_TYPELESS then DXGI_FORMAT_R32_FLOAT or DXGI_FORMAT_R32_UINT could be specified in the Format parameter). |

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)