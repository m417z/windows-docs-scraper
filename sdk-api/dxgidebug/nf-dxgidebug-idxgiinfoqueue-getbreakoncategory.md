# IDXGIInfoQueue::GetBreakOnCategory

## Description

Determines whether the break on a message category is turned on or off.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that gets the breaking status.

### `Category` [in]

A [DXGI_INFO_QUEUE_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_category)-typed value that specifies the category of the message.

## Return value

Returns a Boolean value that specifies whether this category of breaking condition is turned on or off (**TRUE** for on, **FALSE** for off).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)