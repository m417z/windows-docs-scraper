# D3D12_INFO_QUEUE_FILTER_DESC structure

## Description

Allow or deny certain types of messages to pass through a filter.

## Members

### `NumCategories`

Number of message categories to allow or deny.

### `pCategoryList`

Array of message categories to allow or deny. Array must have at least *NumCategories* members (see [D3D12_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_category)).

### `NumSeverities`

Number of message severity levels to allow or deny.

### `pSeverityList`

Array of message severity levels to allow or deny. Array must have at least *NumSeverities* members (see [D3D12_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_severity)).

### `NumIDs`

Number of message IDs to allow or deny.

### `pIDList`

Array of message IDs to allow or deny. Array must have at least *NumIDs* members (see [D3D12_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_id)).

## Remarks

For use with an [ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue) Interface.

## See also

[Debug Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-structures)