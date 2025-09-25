# ID3D10InfoQueue::GetBreakOnID

## Description

Get a message identifier to break on when a message with that identifier passes through the storage filter.

## Parameters

### `ID` [in]

Type: **[D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id)**

Message identifier to break on (see [D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id)).

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Whether this breaking condition is turned on or off (true for on, false for off).

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)