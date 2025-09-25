# ID3D11DeviceContext::ResolveSubresource

## Description

Copy a multisampled resource into a non-multisampled resource.

## Parameters

### `pDstResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Destination resource. Must be a created with the [D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) flag and be single-sampled. See [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource).

### `DstSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index, that identifies the destination subresource. Use [D3D11CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11calcsubresource) to calculate the index.

### `pSrcResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Source resource. Must be multisampled.

### `SrcSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The source subresource of the source resource.

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) that indicates how the multisampled resource will be resolved to a single-sampled resource.
See remarks.

## Remarks

This API is most useful when re-using the resulting rendertarget of one render pass as an input to a second render pass.

The source and destination resources must be the same resource type and have the same dimensions. In addition, they must have compatible formats. There are three scenarios for this:

| Scenario | Requirements |
| --- | --- |
| Source and destination are prestructured and typed | Both the source and destination must have identical formats and that format must be specified in the Format parameter. |
| One resource is prestructured and typed and the other is prestructured and typeless | The typed resource must have a format that is compatible with the typeless resource (i.e. the typed resource is DXGI_FORMAT_R32_FLOAT and the typeless resource is DXGI_FORMAT_R32_TYPELESS). The format of the typed resource must be specified in the Format parameter. |
| Source and destination are prestructured and typeless | Both the source and destination must have the same typeless format (i.e. both must have DXGI_FORMAT_R32_TYPELESS), and the Format parameter must specify a format that is compatible with the source and destination (i.e. if both are DXGI_FORMAT_R32_TYPELESS then DXGI_FORMAT_R32_FLOAT could be specified in the Format parameter).<br><br>For example, given the DXGI_FORMAT_R16G16B16A16_TYPELESS format:<br><br>* The source (or dest) format could be DXGI_FORMAT_R16G16B16A16_UNORM<br>* The dest (or source) format could be DXGI_FORMAT_R16G16B16A16_FLOAT |

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)