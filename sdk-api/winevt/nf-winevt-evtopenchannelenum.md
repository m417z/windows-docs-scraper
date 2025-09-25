# EvtOpenChannelEnum function

## Description

Gets a handle that you use to enumerate the list of channels that are registered on the computer.

## Parameters

### `Session` [in]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** to enumerate the channels on the local computer.

### `Flags` [in]

Reserved. Must be zero.

## Return value

If successful, the function returns a handle to the list of channel names that are registered on the computer; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

The enumeration includes all the channels that the providers that are registered on the computer defined. To enumerate the channel names, call the [EvtNextChannelPath](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnextchannelpath) function in a loop. The names are sorted alphabetically.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the enumerator handle when done.

#### Examples

For an example that shows how to use this function, see [Getting and Setting a Channel's Configuration Properties](https://learn.microsoft.com/windows/desktop/WES/getting-and-setting-a-channel-s-configuration-properties).

## See also

[EvtNextChannelPath](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnextchannelpath)

[EvtOpenChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelconfig)