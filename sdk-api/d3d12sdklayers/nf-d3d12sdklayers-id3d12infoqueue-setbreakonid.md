# ID3D12InfoQueue::SetBreakOnID

## Description

Set a message identifier to break on when a message with that identifier passes through the storage filter.

## Parameters

### `ID` [in]

Type: **[D3D12_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_id)**

Message identifier to break on.

### `bEnable` [in]

Type: **BOOL**

Turns this breaking condition on or off (true for on, false for off).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)