# EvtSaveChannelConfig function

## Description

Saves the changes made to a channel's configuration.

## Parameters

### `ChannelConfig` [in]

A handle to the channel's configuration properties that the [EvtOpenChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelconfig) function returns.

### `Flags` [in]

Reserved. Must be zero.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

To change a channel's configuration property, call the [EvtSetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsetchannelconfigproperty) function.

You must call this function with elevated permissions; otherwise, this function returns ERROR_ACCESS_DENIED.

#### Examples

For an example that shows how to use this function, see [Getting and Setting a Channel's Configuration Properties](https://learn.microsoft.com/windows/desktop/WES/getting-and-setting-a-channel-s-configuration-properties).

## See also

[EvtSetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsetchannelconfigproperty)