# EvtOpenChannelConfig function

## Description

Gets a handle that you use to read or modify a channel's configuration property.

## Parameters

### `Session` [in]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** to access a channel on the local computer.

### `ChannelPath` [in]

The name of the channel to access.

### `Flags` [in]

Reserved. Must be zero.

## Return value

If successful, the function returns a handle to the channel's configuration; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

To get a configuration property, call the [EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty) function.

To modify a configuration property, call the [EvtSetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsetchannelconfigproperty) function. To save the configuration changes, call the [EvtSaveChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsavechannelconfig) function.

To enumerate the registered channels, call the [EvtOpenChannelEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelenum) function.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the handle when done.

#### Examples

For an example that shows how to use this function, see [Getting and Setting a Channel's Configuration Properties](https://learn.microsoft.com/windows/desktop/WES/getting-and-setting-a-channel-s-configuration-properties).

## See also

[EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty)

[EvtOpenChannelEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelenum)

[EvtSaveChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsavechannelconfig)

[EvtSetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsetchannelconfigproperty)