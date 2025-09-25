# ID3D11InfoQueue::GetBreakOnSeverity

## Description

Get a message severity level to break on when a message with that severity level passes through the storage filter.

## Parameters

### `Severity` [in]

Type: **[D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)**

Message severity level to break on (see [D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)).

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Whether this breaking condition is turned on or off (true for on, false for off).

## See also

[ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue)