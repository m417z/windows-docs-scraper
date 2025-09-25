# EvtSetChannelConfigProperty function

## Description

Sets the specified configuration property of a channel.

## Parameters

### `ChannelConfig` [in]

A handle to the channel's configuration properties that the [EvtOpenChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelconfig) function returns.

### `PropertyId` [in]

The identifier of the channel property to set. For a list of property identifiers, see the [EVT_CHANNEL_CONFIG_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_config_property_id) enumeration.

### `Flags` [in]

Reserved. Must be zero.

### `PropertyValue` [in]

The property value to set.

A caller-allocated buffer that contains the new configuration property value. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. Be sure to set the configuration value and variant type.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

This function changes an in-memory copy of the configuration properties. To apply the changes that you have made to one or more of the configuration properties, call the [EvtSaveChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsavechannelconfig) function.

#### Examples

For an example that shows how to use this function, see [Getting and Setting a Channel's Configuration Properties](https://learn.microsoft.com/windows/desktop/WES/getting-and-setting-a-channel-s-configuration-properties).

## See also

[EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty)

[EvtOpenChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenchannelconfig)

[EvtSaveChannelConfig](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsavechannelconfig)