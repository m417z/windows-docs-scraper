# IDXGIInfoQueue::GetBreakOnSeverity

## Description

Determines whether the break on a message severity level is turned on or off.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that gets the breaking status.

### `Severity` [in]

A [DXGI_INFO_QUEUE_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_severity)-typed value that specifies the severity of the message.

## Return value

Returns a Boolean value that specifies whether this severity of breaking condition is turned on or off (**TRUE** for on, **FALSE** for off).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)