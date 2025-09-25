# _HW_STREAM_INFORMATION structure

## Description

The HW_STREAM_INFORMATION structure describes the kernel streaming semantics supported by individual streams, as part of an [HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor) structure.

## Members

### `NumberOfPossibleInstances`

Specifies the number of possible instances of this stream that can be opened.

### `DataFlow`

The direction that data can travel on this stream. For unidirectional data flow, **DataFlow** has the value **KSPIN_DATAFLOW_IN** or KSPIN_DATAFLOW_OUT.

### `DataAccessible`

Specifies **TRUE** if the stream data is accessible to the class driver.

### `NumberOfFormatArrayEntries`

The number of entries in the array that begins at the address in the **StreamFormatsArray** member.

### `StreamFormatsArray`

Pointer to the beginning of the array of data ranges that this stream supports. (The name of this member is deceptive. This member points to an array of [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structures, not KSDATAFORMAT structures.)

### `ClassReserved`

Reserved for use by the class driver. Do not use.

### `NumStreamPropArrayEntries`

The number of entries in the array that begins at the address in the **StreamPropertiesArray** member.

### `StreamPropertiesArray`

Pointer to the beginning of the array of property sets supported by this stream.

### `NumStreamEventArrayEntries`

The number of entries in the array that begins at the address in the **StreamEventsArray** field.

### `StreamEventsArray`

Pointer to the beginning of the array of event sets supported by this stream.

### `Category`

Specifies the GUID of the pin category.

### `Name`

Specifies the GUID of the localized Unicode string name for the pin type, stored in the Registry.

### `MediumsCount`

The number of entries in the array that begins at the address in the **Mediums** field.

### `Mediums`

Pointer to the beginning of the array of [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structures supported by this stream. If the minidriver does not specify a medium, the class driver uses the KSMEDIUMSETID_STANDARD, KSMEDIUM_TYPE_ANYINSTANCE medium as the default.

### `BridgeStream`

If **TRUE**, the communications type of this stream's underlying pin type is KSPIN_COMMUNICATION_BRIDGE. Otherwise, the default communications type of a stream is KSPIN_COMMUNICATION_SINK.

Most minidrivers will set this member to **FALSE**. See KSPROPERTY_PIN_COMMUNICATIONS for a description of communication types.

### `Reserved`

Reserved for use by the class driver. Do not use.

## Remarks

The class driver uses the elements of HW_STREAM_INFORMATION to handle the [KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin) property requests. The index within the [HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor) structure serves as the pin type ID number.

Note that the class driver does not use this data to handle the [KSPROPERTY_PIN_DATAINTERSECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataintersection) property. See [STREAM_DATA_INTERSECT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_stream_data_intersect_info) for a description of how the class driver handles this property.

## See also

[HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor)

[HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header)