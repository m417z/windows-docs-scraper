# ID3D10InfoQueue::GetMessageCountLimit

## Description

Get the maximum number of messages that can be added to the message queue.

## Return value

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of messages that can be added to the queue. -1 means no limit.

## Remarks

When the number of messages in the message queue has reached the maximum limit, new messages coming in will push old messages out.

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)