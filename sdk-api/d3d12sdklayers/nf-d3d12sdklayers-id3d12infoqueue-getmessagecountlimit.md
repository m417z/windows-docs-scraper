# ID3D12InfoQueue::GetMessageCountLimit

## Description

Get the maximum number of messages that can be added to the message queue.

## Return value

Type: **UINT64**

Maximum number of messages that can be added to the queue. -1 means no limit.

When the number of messages in the message queue has reached the maximum limit, new messages coming in will push old messages out.

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)