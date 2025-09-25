# ID3D12InfoQueue::GetBreakOnSeverity

## Description

Get a message severity level to break on when a message with that severity level passes through the storage filter.

## Parameters

### `Severity` [in]

Type: **[D3D12_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_severity)**

Message severity level to break on.

## Return value

Type: **BOOL**

Whether this breaking condition is turned on or off (true for on, false for off).

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)