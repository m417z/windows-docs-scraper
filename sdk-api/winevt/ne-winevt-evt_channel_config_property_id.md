# EVT_CHANNEL_CONFIG_PROPERTY_ID enumeration

## Description

Defines the identifiers that identify the configuration properties of a channel.

## Constants

### `EvtChannelConfigEnabled:0`

Identifies the **enabled** attribute of the channel. The variant type for this property is **EvtVarTypeBoolean**.

You cannot set this property for the Application, System, and Security channels.

### `EvtChannelConfigIsolation`

Identifies the **isolation** attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**. For possible isolation values, see the [EVT_CHANNEL_ISOLATION_TYPE](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_isolation_type) enumeration.

You cannot set this property for the Application, System, and Security channels.

### `EvtChannelConfigType`

Identifies the **type** attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**. For possible isolation values, see the [EVT_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_type) enumeration.

You cannot set this property.

### `EvtChannelConfigOwningPublisher`

Identifies the **name** attribute of the provider that defined the channel. The variant type for this property is **EvtVarTypeString**.

You cannot set this property.

### `EvtChannelConfigClassicEventlog`

Identifies the configuration property that indicates whether the channel is a classic event channel (for example the Application or System log). The variant type for this property is **EvtVarTypeBoolean**.

You cannot set this property.

### `EvtChannelConfigAccess`

Identifies the **access** attribute of the channel. The variant type for this property is **EvtVarTypeString**.

### `EvtChannelLoggingConfigRetention`

Identifies the **retention** logging attribute of the channel. The variant type for this property is **EvtVarTypeBoolean**.

### `EvtChannelLoggingConfigAutoBackup`

Identifies the **autoBackup** logging attribute of the channel. The variant type for this property is **EvtVarTypeBoolean**.

### `EvtChannelLoggingConfigMaxSize`

Identifies the **maxSize** logging attribute of the channel. The variant type for this property is **EvtVarTypeUInt64**.

### `EvtChannelLoggingConfigLogFilePath`

Identifies the configuration property that contains the path to the file that backs the channel. The variant type for this property is **EvtVarTypeString**.

### `EvtChannelPublishingConfigLevel`

Identifies the **level** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**.

To set this property, you must first disable the debug or analytic channel.

### `EvtChannelPublishingConfigKeywords`

Identifies the **keywords** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt64**.

To set this property, you must first disable the debug or analytic channel.

### `EvtChannelPublishingConfigControlGuid`

Identifies the **controlGuid** publishing attribute of the channel. The variant type for this property is **EvtVarTypeGuid**.

You cannot set this property.

### `EvtChannelPublishingConfigBufferSize`

Identifies the **bufferSize** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**.

You cannot set this property.

### `EvtChannelPublishingConfigMinBuffers`

Identifies the **minBuffers** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**.

You cannot set this property.

### `EvtChannelPublishingConfigMaxBuffers`

Identifies the **maxBuffers** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**.

You cannot set this property.

### `EvtChannelPublishingConfigLatency`

Identifies the **latency** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**.

You cannot set this property.

### `EvtChannelPublishingConfigClockType`

Identifies the **clockType** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**. For possible clock type values, see the [EVT_CHANNEL_CLOCK_TYPE](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_clock_type) enumeration.

You cannot set this property.

### `EvtChannelPublishingConfigSidType`

Identifies the **sidType** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**. For possible SID type values, see the [EVT_CHANNEL_SID_TYPE](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_channel_sid_type) enumeration.

You cannot set this property.

### `EvtChannelPublisherList`

Identifies the configuration property that contains the list of providers that import this channel. The variant type for this property is **EvtVarTypeString \| EVT_VARIANT_TYPE_ARRAY**.

You cannot set this property.

### `EvtChannelPublishingConfigFileMax`

Identifies the **fileMax** publishing attribute of the channel. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtChannelConfigPropertyIdEND`

This enumeration value marks the end of the enumeration values.

## See also

[ChannelLoggingType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channelloggingtype-complextype)

[ChannelPublishingType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channelpublishingtype-complextype)

[ChannelType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channeltype-complextype)

[EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty)

[EvtSetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsetchannelconfigproperty)