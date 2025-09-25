# IDXGIInfoQueue::AddMessage

## Description

Adds a debug message to the message queue and sends that message to the debug output.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that produced the message.

### `Category` [in]

A [DXGI_INFO_QUEUE_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_category)-typed value that specifies the category of the message.

### `Severity` [in]

A [DXGI_INFO_QUEUE_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_severity)-typed value that specifies the severity of the message.

### `ID` [in]

An integer that uniquely identifies the message.

### `pDescription` [in]

The message string.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)