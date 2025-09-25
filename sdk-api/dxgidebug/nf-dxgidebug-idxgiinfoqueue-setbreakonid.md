# IDXGIInfoQueue::SetBreakOnID

## Description

Sets a message identifier to break on when a message with that identifier passes through the storage filter.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that sets the breaking condition.

### `ID` [in]

An integer value that specifies the identifier of the message.

### `bEnable` [in]

A Boolean value that specifies whether **SetBreakOnID** turns on or off this breaking condition (**TRUE** for on, **FALSE** for off).

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)