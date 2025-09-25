# D3D11_INFO_QUEUE_FILTER structure

## Description

Debug message filter; contains a lists of message types to allow or deny.

## Members

### `AllowList`

Type: **[D3D11_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter_desc)**

Types of messages that you want to allow. See [D3D11_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter_desc).

### `DenyList`

Type: **[D3D11_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter_desc)**

Types of messages that you want to deny.

## Remarks

For use with an [ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-structures)