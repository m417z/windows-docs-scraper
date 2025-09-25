# ID3D10InfoQueue::AddApplicationMessage

## Description

Add a user-defined message to the message queue and send that message to debug output.

## Parameters

### `Severity` [in]

Type: **[D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity)**

Severity of a message (see [D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity)).

### `pDescription` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Message string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)