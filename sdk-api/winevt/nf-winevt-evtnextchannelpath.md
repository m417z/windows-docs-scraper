# EvtNextChannelPath function

## Description

Gets a channel name from the enumerator.

## Parameters

### `ChannelEnum` [in]

A handle to the enumerator that the [EvtOpenChannelEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelenum) function returns.

### `ChannelPathBufferSize` [in]

The size of the *ChannelPathBuffer* buffer, in characters.

### `ChannelPathBuffer` [in]

A caller-allocated buffer that will receive the name of the channel. You can set this parameter to **NULL** to determine the required buffer size.

### `ChannelPathBufferUsed` [out]

The size, in characters, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

Call this function in a loop until the function returns **FALSE** and the error code is ERROR_NO_MORE_ITEMS.

#### Examples

For an example that shows how to use this function, see [Getting and Setting a Channel's Configuration Properties](https://learn.microsoft.com/windows/desktop/WES/getting-and-setting-a-channel-s-configuration-properties).

## See also

[EvtOpenChannelEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelenum)