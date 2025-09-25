# DXGI_INFO_QUEUE_FILTER_DESC structure

## Description

Describes the types of messages to allow or deny to pass through a filter.

## Members

### `NumCategories`

The number of message categories to allow or deny.

### `pCategoryList`

An array of [DXGI_INFO_QUEUE_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_category) enumeration values that describe the message categories to allow or deny. The array must have at least **NumCategories** number of elements.

### `NumSeverities`

The number of message severity levels to allow or deny.

### `pSeverityList`

An array of [DXGI_INFO_QUEUE_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_severity) enumeration values that describe the message severity levels to allow or deny. The array must have at least **NumSeverities** number of elements.

### `NumIDs`

The number of message IDs to allow or deny.

### `pIDList`

An array of integers that represent the message IDs to allow or deny. The array must have at least **NumIDs** number of elements.

## Remarks

This structure is a member of the [DXGI_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ns-dxgidebug-dxgi_info_queue_filter) structure.

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)