# ID3D11InfoQueue::AddMessage

## Description

Add a debug message to the message queue and send that message to debug output.

## Parameters

### `Category` [in]

Type: **[D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category)**

Category of a message (see [D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category)).

### `Severity` [in]

Type: **[D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)**

Severity of a message (see [D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)).

### `ID` [in]

Type: **[D3D11_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_id)**

Unique identifier of a message (see [D3D11_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_id)).

### `pDescription` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

User-defined message.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This method is used by the runtime's internal mechanisms to add debug messages to the message queue and send them to debug output. For applications to add their own custom messages to the message queue and send them to debug output, call [ID3D11InfoQueue::AddApplicationMessage](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11infoqueue-addapplicationmessage).

## See also

[ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue)