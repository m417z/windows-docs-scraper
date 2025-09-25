# EVT_PUBLISHER_METADATA_PROPERTY_ID enumeration

## Description

Defines the identifiers that identify the metadata properties of a provider.

## Constants

### `EvtPublisherMetadataPublisherGuid:0`

Identifies the **guid** attribute of the provider. The variant type for this property is **EvtVarTypeGuid**.

### `EvtPublisherMetadataResourceFilePath`

Identifies the **resourceFilePath** attribute of the provider. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataParameterFilePath`

Identifies the **parameterFilePath** attribute of the provider. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataMessageFilePath`

Identifies the **messageFilePath** attribute of the provider. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataHelpLink`

Identifies the **helpLink** attribute of the provider. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataPublisherMessageID`

Identifies the **message** attribute of the provider. The metadata is the resource identifier assigned to the message string. To get the message string, call the [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage) function. The variant type for this property is **EvtVarTypeUInt32**. If the provider does not specify a message, the value is –1.

### `EvtPublisherMetadataChannelReferences`

Identifies the **channels** child element of the provider. The variant type for this property is **EvtVarTypeEvtHandle**. To access the metadata of the channels that the provider defines or imports, use this handle when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. When you are done with the handle, call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

### `EvtPublisherMetadataChannelReferencePath`

Identifies the **name** attribute of the channel. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataChannelReferenceIndex`

Identifies the zero-based index value of the channel in the list of channels. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtPublisherMetadataChannelReferenceID`

Identifies the **value** attribute of the channel. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtPublisherMetadataChannelReferenceFlags`

Identifies the flags value that indicates whether this channel is imported from another provider. The channel is imported if the EvtChannelReferenceImported flag value is set. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtPublisherMetadataChannelReferenceMessageID`

Identifies the **message** attribute of the channel. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**. The property contains the resource identifier that is assigned to the message string. To get the message string, call the [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage) function. If the channel does not specify a message, the value is –1.

### `EvtPublisherMetadataLevels`

Identifies the **levels** child element of the provider. The variant type for this property is **EvtVarTypeEvtHandle**. To access the metadata of the levels that the provider defines or references, use this handle when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. When you are done with the handle, call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

### `EvtPublisherMetadataLevelName`

Identifies the **name** attribute of the level. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataLevelValue`

Identifies the **value** attribute of the level. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtPublisherMetadataLevelMessageID`

Identifies the **message** attribute of the level. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**. The property contains the resource identifier that is assigned to the message string. To get the message string, call the [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage) function. If the level does not specify a message, the value is –1.

### `EvtPublisherMetadataTasks`

Identifies the **tasks** child element of the provider. The variant type for this property is **EvtVarTypeEvtHandle**. To access the metadata of the tasks that the provider defines, use this handle when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. When you are done with the handle, call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

### `EvtPublisherMetadataTaskName`

Identifies the **name** attribute of the task. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataTaskEventGuid`

Identifies the **eventGuid** attribute of the task. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataTaskValue`

Identifies the **value** attribute of the task. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtPublisherMetadataTaskMessageID`

Identifies the **message** attribute of the task. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**. The property contains the resource identifier that is assigned to the message string. To get the message string, call the [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage) function. If the task does not specify a message, the value is –1.

### `EvtPublisherMetadataOpcodes`

Identifies the **opcodes** child element of the provider. The variant type for this property is **EvtVarTypeEvtHandle**. To access the metadata of the opcodes that the provider defines or references, use this handle when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. When you are done with the handle, call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

### `EvtPublisherMetadataOpcodeName`

Identifies the **name** attribute of the opcode. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataOpcodeValue`

Identifies the **value** attribute of the opcode. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**. The high word contains the opcode value and the low word contains the task to which it belongs. If the low word is zero, the opcode is defined globally; otherwise, the opcode is task specific. Use the low word value to determine the task that defines the opcode.

### `EvtPublisherMetadataOpcodeMessageID`

Identifies the **message** attribute of the opcode. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**. The property contains the resource identifier that is assigned to the message string. To get the message string, call the [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage) function. If the opcode does not specify a message, the value is –1.

### `EvtPublisherMetadataKeywords`

Identifies the **keywords** child element of the provider. The variant type for this property is **EvtVarTypeEvtHandle**. To access the metadata of the keywords that the provider defines, use this handle when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. When you are done with the handle, call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

### `EvtPublisherMetadataKeywordName`

Identifies the **name** attribute of the keyword. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeString**.

### `EvtPublisherMetadataKeywordValue`

Identifies the **mask** attribute of the keyword. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt64**.

### `EvtPublisherMetadataKeywordMessageID`

Identifies the **message** attribute of the keyword. Use this identifier when calling the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function. For details, see Remarks. The variant type for this property is **EvtVarTypeUInt32**. The property contains the resource identifier that is assigned to the message string. To get the message string, call the [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage) function. If the keyword does not specify a message, the value is –1.

### `EvtPublisherMetadataPropertyIdEND`

This enumeration value marks the end of the enumeration values.

## Remarks

This list of identifiers in this enumeration are for those properties that cannot change. To get the configuration for a channel, call the [EvtGetChannelConfigProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetchannelconfigproperty) function.

You cannot use the following property identifiers when calling the [EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty) function:

* **EvtPublisherMetadataChannelReferencePath**
* **EvtPublisherMetadataChannelReferenceIndex**
* **EvtPublisherMetadataChannelReferenceID**
* **EvtPublisherMetadataChannelReferenceFlags**
* **EvtPublisherMetadataChannelReferenceMessageID**
* **EvtPublisherMetadataLevelName**
* **EvtPublisherMetadataLevelValue**
* **EvtPublisherMetadataLevelMessageID**
* **EvtPublisherMetadataTaskName**
* **EvtPublisherMetadataTaskEventGuid**
* **EvtPublisherMetadataTaskValue**
* **EvtPublisherMetadataTaskMessageID**
* **EvtPublisherMetadataOpcodeName**
* **EvtPublisherMetadataOpcodeValue**
* **EvtPublisherMetadataOpcodeMessageID**
* **EvtPublisherMetadataKeywordName**
* **EvtPublisherMetadataKeywordValue**
* **EvtPublisherMetadataKeywordMessageID**

To use these identifiers, you must first retrieve the handle to the property's parent object. To retrieve the channel properties, you must first retrieve the handle to the parent object using the **EvtPublisherMetadataChannelReferences** identifier; to retrieve the level properties, you must first retrieve the handle to the parent object using the **EvtPublisherMetadataLevels** identifier; to retrieve the task properties, you must first retrieve the handle to the parent object using the **EvtPublisherMetadataTasks** identifier; to retrieve the opcode properties, you must first retrieve the handle to the parent object using the **EvtPublisherMetadataOpcodes** identifier; and to retrieve the keyword properties, you must first retrieve the handle to the parent object using the **EvtPublisherMetadataKeywords** identifier.

The handle points to an array of objects that contain the metadata for child type that the provider defines. To determine how many objects are in the array, call the [EvtGetObjectArraySize](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarraysize) function. To access a property of one of the objects, call the [EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty) function and specify the identifier of the property that you want to retrieve.

## See also

[ChannelType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channeltype-complextype)

[EVT_EVENT_METADATA_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_event_metadata_property_id)

[EVT_VARIANT_TYPE](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_variant_type)

[EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty)

[ProviderType Complex Type](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-providertype-complextype)