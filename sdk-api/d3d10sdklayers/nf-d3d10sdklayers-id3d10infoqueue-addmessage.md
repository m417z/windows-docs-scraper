# ID3D10InfoQueue::AddMessage

## Description

Add a Direct3D 10 debug message to the message queue and send that message to debug output.

## Parameters

### `Category` [in]

Type: **[D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category)**

Category of a message (see [D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category)).

### `Severity` [in]

Type: **[D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity)**

Severity of a message (see [D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity)).

### `ID` [in]

Type: **[D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id)**

Unique identifier of a message (see [D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id)).

### `pDescription` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

User-defined message.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This method is used by the runtime's internal mechanisms to add Direct3D 10 debug messages to the message queue and send them to debug output. For applications to add their own custom messages to the message queue and send them to debug output, call [ID3D10InfoQueue::AddApplicationMessage](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-addapplicationmessage).

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)