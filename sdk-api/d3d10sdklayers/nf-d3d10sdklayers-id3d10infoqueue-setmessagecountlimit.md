# ID3D10InfoQueue::SetMessageCountLimit

## Description

Set the maximum number of messages that can be added to the message queue.

## Parameters

### `MessageCountLimit` [in]

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum number of messages that can be added to the message queue. -1 means no limit.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

When the number of messages in the message queue has reached the maximum limit, new messages coming in will push old messages out.

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)