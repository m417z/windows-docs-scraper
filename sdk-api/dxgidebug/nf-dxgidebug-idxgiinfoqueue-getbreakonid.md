# IDXGIInfoQueue::GetBreakOnID

## Description

Determines whether the break on a message identifier is turned on or off.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that gets the breaking status.

### `ID` [in]

An integer value that specifies the identifier of the message.

## Return value

Returns a Boolean value that specifies whether this break on a message identifier is turned on or off (**TRUE** for on, **FALSE** for off).

## Remarks

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)