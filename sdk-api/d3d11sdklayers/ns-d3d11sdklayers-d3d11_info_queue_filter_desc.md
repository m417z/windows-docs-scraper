# D3D11_INFO_QUEUE_FILTER_DESC structure

## Description

Allow or deny certain types of messages to pass through a filter.

## Members

### `NumCategories`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of message categories to allow or deny.

### `pCategoryList`

Type: **[D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category)***

Array of message categories to allow or deny. Array must have at least NumCategories members (see [D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category)).

### `NumSeverities`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of message severity levels to allow or deny.

### `pSeverityList`

Type: **[D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)***

Array of message severity levels to allow or deny. Array must have at least NumSeverities members (see [D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)).

### `NumIDs`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of message IDs to allow or deny.

### `pIDList`

Type: **[D3D11_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_id)***

Array of message IDs to allow or deny. Array must have at least NumIDs members (see [D3D11_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_id)).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-structures)