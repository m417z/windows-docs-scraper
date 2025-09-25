# D3D10_INFO_QUEUE_FILTER structure

## Description

Debug message filter; contains a lists of message types to allow or deny.

## Members

### `AllowList`

Type: **[D3D10_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter_desc)**

A [D3D10_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter_desc) structure describing the types of messages the info queue should allow.

### `DenyList`

Type: **[D3D10_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter_desc)**

A [D3D10_INFO_QUEUE_FILTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter_desc) structure describing the types of messages the info queue should reject.

## Remarks

For use with an [ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue).

Providing an allow list with non-zero values causes only the specified combination of categories, severities and message IDs to be allowed.
Messages that do not match the specified combination will be rejected.

Providing a deny list with non-zero values causes the specified combination of categories, severities and message IDs to be rejected.
Messages that do not match the specified combination will be allowed.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)