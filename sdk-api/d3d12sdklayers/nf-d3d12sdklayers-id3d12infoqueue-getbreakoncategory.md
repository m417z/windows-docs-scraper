# ID3D12InfoQueue::GetBreakOnCategory

## Description

Get a message category to break on when a message with that category passes through the storage filter.

## Parameters

### `Category` [in]

Type: **[D3D12_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_category)**

Message category to break on.

## Return value

Type: **BOOL**

Whether this breaking condition is turned on or off (true for on, false for off).

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)