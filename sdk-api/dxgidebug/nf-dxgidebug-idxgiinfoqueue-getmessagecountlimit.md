# IDXGIInfoQueue::GetMessageCountLimit

## Description

Gets the maximum number of messages that can be added to the message queue.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that gets the number.

## Return value

Returns the maximum number of messages that can be added to the queue. –1 means no limit.

## Remarks

When the number of messages in the message queue reaches the maximum limit, new messages coming in push old messages out.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)