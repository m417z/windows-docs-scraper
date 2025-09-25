# D3D12_INFO_QUEUE_FILTER structure

## Description

Debug message filter; contains a lists of message types to allow or deny.

## Members

### `AllowList`

Specifies types of messages that you want to allow. See [D3D12_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_info_queue_filter_desc).

### `DenyList`

Specifies types of messages that you want to deny.

## Remarks

For use with an [ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue) Interface.

## See also

[Debug Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-structures)