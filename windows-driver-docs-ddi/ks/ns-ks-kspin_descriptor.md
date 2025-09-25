# KSPIN_DESCRIPTOR structure

## Description

The KSPIN_DESCRIPTOR structure describes the basic [KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin) properties of a pin type.

## Members

### `InterfacesCount`

Specifies the size of the array pointed to by **Interfaces**.

### `Interfaces`

An array of [KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure) structures specifying the interfaces supported by this pin type.

### `MediumsCount`

Specifies the number of elements in the array pointed to by **Mediums**.

### `Mediums`

An array of [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structures specifying the mediums supported by this pin type.

### `DataRangesCount`

Specifies the size of the array pointed to by **DataRanges**.

### `DataRanges`

An array of [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structures specifying the data ranges supported by this pin type.

### `DataFlow`

Specifies either **KSPIN_DATAFLOW_IN** or KSPIN_DATAFLOW_OUT. See [KSPROPERTY_PIN_DATAFLOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataflow).

### `Communication`

Specifies KSPIN_COMMUNICATION_NONE, KSPIN_COMMUNICATION_SINK, KSPIN_COMMUNICATION_SOURCE, KSPIN_COMMUNICATION_BOTH or KSPIN_COMMUNICATION_BRIDGE. See [KSPROPERTY_PIN_COMMUNICATION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-communication) for the meaning of each value.

### `Category`

Specifies a pointer to a KS pin category GUID. The KS pin category GUID identifies the general category of functionality that the pin provides. Examples of KS pin category GUIDs are KSNODETYPE_SPEAKER, KSNODETYPE_HEADPHONES, and KSNODETYPE_MICROPHONE, which are all defined in *Ksmedia.h*. Also see [Pin Category Property](https://learn.microsoft.com/windows-hardware/drivers/audio/pin-category-property).

### `Name`

Specifies the GUID of the localized Unicode string name for the pin type, stored in the Registry.

### `Reserved`

Not used. A member of an unnamed union used to force proper alignment on the unnamed structure.

### `ConstrainedDataRangesCount`

Specifies the number of entries in the array pointed to by **ConstrainedDataRanges**.

### `ConstrainedDataRanges`

Points to an array of [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structures. Indicates the set of data ranges the pin type currently supports, based on the driver's internal state.

## Remarks

Drivers typically define one KSPIN_DESCRIPTOR structure for each pin type they support.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure)

[KSPROPERTY_PIN_COMMUNICATION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-communication)

[KSPROPERTY_PIN_DATAFLOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataflow)

[KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin)