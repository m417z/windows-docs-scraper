# IDXGIInfoQueue::GetNumMessagesDiscardedByMessageCountLimit

## Description

Gets the number of messages that were discarded due to the message count limit.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that gets the number.

## Return value

Returns the number of messages that were discarded.

## Remarks

Get and set the message count limit with [IDXGIInfoQueue::GetMessageCountLimit](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-getmessagecountlimit) and [IDXGIInfoQueue::SetMessageCountLimit](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-setmessagecountlimit), respectively.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)