# ID3D12InfoQueue::AddApplicationMessage

## Description

Adds a user-defined message to the message queue and sends that message to debug output.

## Parameters

### `Severity` [in]

Type: **[D3D12_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_severity)**

Severity of a message.

### `pDescription` [in]

Type: **LPCSTR**

Specifies the message string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)