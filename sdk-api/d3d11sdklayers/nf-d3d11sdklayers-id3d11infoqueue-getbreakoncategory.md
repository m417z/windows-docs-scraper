# ID3D11InfoQueue::GetBreakOnCategory

## Description

Get a message category to break on when a message with that category passes through the storage filter.

## Parameters

### `Category` [in]

Type: **[D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category)**

Message category to break on (see [D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category)).

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Whether this breaking condition is turned on or off (true for on, false for off).

## See also

[ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue)