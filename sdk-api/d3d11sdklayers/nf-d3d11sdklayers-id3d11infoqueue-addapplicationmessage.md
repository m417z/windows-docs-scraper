# ID3D11InfoQueue::AddApplicationMessage

## Description

Add a user-defined message to the message queue and send that message to debug output.

## Parameters

### `Severity` [in]

Type: **[D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)**

Severity of a message (see [D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)).

### `pDescription` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Message string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue)