# TRACE_EVENT_INFO structure

## Description

Defines the information about the event.

## Members

### `ProviderGuid`

A GUID that identifies the provider.

### `EventGuid`

A GUID that identifies the MOF class that contains the event. If the provider uses a manifest to define its events, this member is GUID_NULL.

### `EventDescriptor`

A [EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor) structure that describes the event.

### `DecodingSource`

A [DECODING_SOURCE](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-decoding_source) enumeration value that identifies the source used to parse the event's data (for example, an instrumentation manifest of WMI MOF class).

### `ProviderNameOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the name of the provider.

### `LevelNameOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the name of the level. For possible names, see Remarks in [LevelType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-leveltype-complextype).

### `ChannelNameOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the name of the channel. For possible names, see Remarks in [ChannelType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channeltype-complextype).

### `KeywordsNameOffset`

The offset from the beginning of this structure to a list of null-terminated Unicode strings that contains the names of the keywords. The list is terminated with two NULL characters. For possible names, see Remarks in [KeywordType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-keywordtype-complextype).

### `TaskNameOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the name of the task. For possible names, see Remarks in [TaskType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-tasktype-complextype).

### `OpcodeNameOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the name of the operation. For possible names, see Remarks in [OpcodeType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-opcodetype-complextype).

### `EventMessageOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the event message string. The offset is zero if there is no message string. For information on message strings, see the **message** attribute for [EventDefinitionType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-eventdefinitiontype-complextype).

The message string can contain insert sequences, for example, Unable to connect to the %1 printer. The number of the insert sequence identifies the property in the event data to use for the substitution.

### `ProviderMessageOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the localized provider name.

### `BinaryXMLOffset`

Reserved.

### `BinaryXMLSize`

Reserved.

### `EventNameOffset`

### `ActivityIDNameOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the property name of the activity identifier in the MOF class. Supported for classic ETW events only.

### `EventAttributesOffset`

### `RelatedActivityIDNameOffset`

The offset from the beginning of this structure to a null-terminated Unicode string that contains the property name of the related activity identifier in the MOF class. Supported for legacy ETW events only.

### `PropertyCount`

The number of elements in the **EventPropertyInfoArray** array.

### `TopLevelPropertyCount`

The number of properties in the **EventPropertyInfoArray** array that are top-level properties. This number does not include members of structures. Top-level properties come before all member properties in the array.

### `Flags`

Reserved.

### `Reserved`

### `Tags`

A 28-bit value associated with the event metadata. This value can be used by the event provider to associate additional semantic data with an event for use by an event processing tool. For example, a tag value of 5 might indicate that the event contains debugging information. The semantics of any values in this field are defined by the event provider.

### `EventPropertyInfoArray`

An array of [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info) structures that provides information about each property of the event's user data.

## Remarks

The value of an offset is zero if the member is not defined.

## See also
[ChannelType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-channeltype-complextype)

[DECODING_SOURCE](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-decoding_source)

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)

[EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-event_property_info)

[EventDefinitionType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-eventdefinitiontype-complextype)

[KeywordType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-keywordtype-complextype)

[LevelType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-leveltype-complextype)

[OpcodeType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-opcodetype-complextype)

[TaskType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-tasktype-complextype)

[TdhEnumerateManifestProviderEvents](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumeratemanifestproviderevents)

[TdhGetEventInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgeteventinformation)

[TdhGetManifestEventInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetmanifesteventinformation)