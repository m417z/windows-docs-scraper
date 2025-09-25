# DXGI_INFO_QUEUE_FILTER structure

## Description

Describes a debug message filter, which contains lists of message types to allow and deny.

## Members

### `AllowList`

A [DXGI_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ns-dxgidebug-dxgi_info_queue_filter_desc) structure that describes the types of messages to allow.

### `DenyList`

A [DXGI_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ns-dxgidebug-dxgi_info_queue_filter_desc) structure that describes the types of messages to deny.

## Remarks

Use with an [IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue) interface.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)