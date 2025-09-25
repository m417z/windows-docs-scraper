# D3D10_INFO_QUEUE_FILTER_DESC structure

## Description

Allow or deny certain types of messages to pass through a filter.

## Members

### `NumCategories`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of message categories to allow or deny.

### `pCategoryList`

Type: **[D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category)***

Array of message categories to allow or deny. Array must have at least NumCategories members (see [D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category)).

### `NumSeverities`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of message severity levels to allow or deny.

### `pSeverityList`

Type: **[D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity)***

Array of message severity levels to allow or deny. Array must have at least NumSeverities members (see [D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity)).

### `NumIDs`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of message IDs to allow or deny.

### `pIDList`

Type: **[D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id)***

Array of message IDs to allow or deny. Array must have at least NumIDs members (see [D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id)).

## Remarks

**D3D10_INFO_QUEUE_FILTER_DESC** is used to define the allow list and deny list in the [D3D10_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)