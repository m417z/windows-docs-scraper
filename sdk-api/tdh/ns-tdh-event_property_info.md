# EVENT_PROPERTY_INFO structure

## Description

Provides information about a single property of the event or filter.

## Members

### `Flags`

Flags that indicate if the property is contained in a structure or array. For possible values, see the [PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-property_flags) enumeration.

### `NameOffset`

Offset to a null-terminated Unicode string that contains the name of the property. If this an event property, the offset is from the beginning of the [TRACE_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-trace_event_info) structure. If this is a filter property, the offset is from the beginning of the [PROVIDER_FILTER_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_filter_info) structure.

### `nonStructType`

Use these members if the [PropertyStruct](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-property_flags) flag in **Flags** is not set; otherwise, use the **structType** member.

### `nonStructType.InType`

Data type of this property on input. For a description of these types, see Remarks in [InputType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-inputtype-complextype).

For descriptions of these types, see [Event Tracing MOF Qualifiers](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-mof-qualifiers).

[TdhGetPropertySize](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetpropertysize)
[TdhGetPropertySize](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetpropertysize)

### `nonStructType.OutType`

Output format for this property. If the value is TDH_OUTTYPE_NULL, use the in type as the output format. For a description of these types, see Remarks in [InputType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-inputtype-complextype).

For descriptions of these types, see [Event Tracing MOF Qualifiers](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-mof-qualifiers).

### `nonStructType.MapNameOffset`

Offset from the beginning of the [TRACE_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-trace_event_info) structure to a null-terminated Unicode string that contains the name of the map attribute value. You can pass this string to [TdhGetEventMapInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgeteventmapinformation) to retrieve information about the value map.

### `structType`

Use these members if the [PropertyStruct](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-property_flags) flag in **Flags** is set; otherwise, use the **nonStructType** member.

### `structType.StructStartIndex`

Zero-based index to the element of the property array that contains the first member of the structure.

### `structType.NumOfStructMembers`

Number of members in the structure.

### `structType.padding`

Not used.

### `customSchemaType`

Use these members if the **PropertyHasCustomSchema** flag in **Flags** is set; otherwise, use the **nonStructType** member.

### `customSchemaType.padding2`

This value is not used for **customSchemaType**. For compatibility with decoders that do not recognize custom schema properties, this value will contain a TDH InType such as TDH_INTYPE_BINARY.

### `customSchemaType.OutType`

Output format for this property. If the value is TDH_OUTTYPE_NULL, use the in type as the output format. For a description of these types, see Remarks in [InputType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-inputtype-complextype).

For descriptions of these types, see [Event Tracing MOF Qualifiers](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-mof-qualifiers).

### `customSchemaType.CustomSchemaOffset`

Offset (in bytes) from the beginning of the TRACE_EVENT_INFO structure to the custom schema information. The custom schema information will contain a 2-byte protocol identifier, followed by a 2-byte schema length, followed by the schema.

### `count`

Number of elements in the array. Note that this value is 1 for properties that are not defined as an array.

### `countPropertyIndex`

Zero-based index to the element of the property array that contains the number of elements in the array. Use this member if the [PropertyParamCount](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-property_flags) flag in **Flags** is set; otherwise, use the **count** member.

### `length`

Size of the property, in bytes. Note that variable-sized types such as strings and binary data have a length of zero unless the property has length attribute to explicitly indicate its real length. Structures have a length of zero.

### `lengthPropertyIndex`

Zero-based index to the element of the property array that contains the size value of this property. Use this member if the [PropertyParamLength](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-property_flags) flag in **Flags** is set; otherwise, use the **length** member.

### `Reserved`

Reserved.

### `Tags`

A 28-bit value associated with the field metadata. This value is valid only if the *PropertyHasTags* flag is set. This value can be used by the event provider to associate additional semantic data with a field for use by an event processing tool. For example, a tag value of 1 might indicate that the field contains a username. The semantics of any values in this field are defined by the event provider.

## Remarks

Filters do not support maps, structures, or arrays.

## See also
[PROVIDER_FILTER_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_filter_info)

[TRACE_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-trace_event_info)