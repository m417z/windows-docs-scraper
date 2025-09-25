# EVT_EVENT_METADATA_PROPERTY_ID enumeration

## Description

Defines the identifiers that identify the metadata properties of an event definition.

## Constants

### `EventMetadataEventID`

Identifies the **value** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt32**.

### `EventMetadataEventVersion`

Identifies the **version** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt32**.

### `EventMetadataEventChannel`

Identifies the **channel** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt32**. This property does not contain the channel identifier that you specified in the event definition but instead contains the **value** attribute of the channel. The value is zero if the event definition does not specify a channel.

### `EventMetadataEventLevel`

Identifies the **level** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt32**. This property does not contain the level name that you specified in the event definition but instead contains the **value** attribute of the level. The value is zero if the event definition does not specify a level.

### `EventMetadataEventOpcode`

Identifies the **opcode** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt32**. This property does not contain the opcode name that you specified in the event definition but instead contains the **value** attribute of the opcode. The value is zero if the event definition does not specify an opcode.

### `EventMetadataEventTask`

Identifies the **task** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt32**. This property does not contain the task name that you specified in the event definition but instead contains the **value** attribute of the task. The value is zero if the event definition does not specify a task.

### `EventMetadataEventKeyword`

Identifies the **keyword** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt64**. This property does not contain the list of keyword names that you specified in the event definition but instead contains a 64-bitmask of all the keywords. The top 16 bits of the mask are reserved for internal use and should be ignored when determining the keyword bits that the event definition set.

### `EventMetadataEventMessageID`

Identifies the **message** attribute of the event definition. The variant type for this property is **EvtVarTypeUInt32**. The property contains the resource identifier that is assigned to the message string. To get the message string, call the [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage) function. If the event definition does not specify a message, the value is –1.

### `EventMetadataEventTemplate`

Identifies the **template** attribute of the event definition. The variant type for this property is **EvtVarTypeString**. This property does not contain the template name that you specified in the event definition but instead contains an XML string that includes the template node and each data node; the string does not include the UserData. The value is an empty string if the event definition does not specify a template.

### `EvtEventMetadataPropertyIdEND`

This enumeration value marks the end of the enumeration values.

## Remarks

The channel, level, opcode, task, and keyword properties return the value of the value attribute. To get the metadata for a property whose value is not zero, call the [EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty) function for the property. For example, to get the metadata for the task property, call **EvtGetPublisherMetadataProperty** using the EvtPublisherMetadataTasks provider property identifier. The function returns an array of task objects that you enumerate. For each object, compare the value of the object's value property to the value specified in the event. If the values match, use the metadata from that object.

## See also

[EventDefinitionType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-eventdefinitiontype-complextype)

[EvtGetEventMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgeteventmetadataproperty)