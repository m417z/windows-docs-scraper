# ID3D12InfoQueue::AddMessage

## Description

Adds a debug message to the message queue and sends that message to debug output.

## Parameters

### `Category` [in]

Type: **[D3D12_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_category)**

Category of a message.

### `Severity` [in]

Type: **[D3D12_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_severity)**

Severity of a message.

### `ID` [in]

Type: **[D3D12_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_id)**

Unique identifier of a message.

### `pDescription` [in]

Type: **LPCSTR**

User-defined message.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This method is used by the runtime's internal mechanisms to add debug messages to the message queue and send them to debug output. For applications to add their own custom messages to the message queue and send them to debug output, call [ID3D12InfoQueue::AddApplicationMessage](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12infoqueue-addapplicationmessage).

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)