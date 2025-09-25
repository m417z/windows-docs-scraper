# ID3D12InfoQueue::SetMessageCountLimit

## Description

Set the maximum number of messages that can be added to the message queue.

## Parameters

### `MessageCountLimit` [in]

Type: **UINT64**

Maximum number of messages that can be added to the message queue. -1 means no limit.

When the number of messages in the message queue has reached the maximum limit, new messages coming in will push old messages out.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)