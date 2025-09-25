# ID3D10InfoQueue::SetBreakOnCategory

## Description

Set a message category to break on when a message with that category passes through the storage filter.

## Parameters

### `Category` [in]

Type: **[D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category)**

Message category to break on (see [D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category)).

### `bEnable` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Turns this breaking condition on or off (true for on, false for off).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)