# EVT_CHANNEL_ISOLATION_TYPE enumeration

## Description

Defines the default access permissions to apply to the channel.

## Constants

### `EvtChannelIsolationTypeApplication:0`

Provides open access to the channel.

### `EvtChannelIsolationTypeSystem`

Provides restricted access to the channel and is used by applications running under system service accounts, drivers, or an application that logs events that relate to the health of the computer.

### `EvtChannelIsolationTypeCustom`

Provides custom access to the channel.

## See also

[ChannelType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channeltype-complextype)

[EVT_CHANNEL_CONFIG_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_config_property_id)

[EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty)

[EvtSetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsetchannelconfigproperty)