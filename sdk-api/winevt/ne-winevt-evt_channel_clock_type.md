# EVT_CHANNEL_CLOCK_TYPE enumeration

## Description

Defines the values that specify the type of time stamp to use when logging events channel.

## Constants

### `EvtChannelClockTypeSystemTime:0`

Uses the system time for the time stamp. The system time provides a low-resolution (10 milliseconds) time stamp but is comparatively less expensive to retrieve. System time is the default.

Note that if the volume of events is high, the resolution for system time may not be fine enough to determine the sequence of events. If multiple events contain the same time stamp, the events may be delivered in the wrong order.

### `EvtChannelClockTypeQPC`

Uses the query performance counter (QPC) for the time stamp. The QPC time stamp provides a high-resolution (100 nanoseconds) time stamp but is comparatively more expensive to retrieve.

You should use this resolution if you have high event rates or if the consumer merges events from different buffers.

Note that on older computers, the time stamp may not be accurate because the counter sometimes skips forward due to hardware errors.

## See also

[ChannelType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channeltype-complextype)

[EVT_CHANNEL_CONFIG_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_config_property_id)

[EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty)

[EvtSetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsetchannelconfigproperty)