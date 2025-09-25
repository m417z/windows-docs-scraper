# EVT_CHANNEL_SID_TYPE enumeration

## Description

Defines the values that determine whether the event includes the security identifier (SID) of the principal that logged the event.

## Constants

### `EvtChannelSidTypeNone:0`

Do not include with the event the SID of the principal that logged the event.

### `EvtChannelSidTypePublishing`

Include with the event the SID of the principal that logged the event.

## See also

[ChannelPublishingType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channelpublishingtype-complextype)

[EVT_CHANNEL_CONFIG_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_config_property_id)

[EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty)