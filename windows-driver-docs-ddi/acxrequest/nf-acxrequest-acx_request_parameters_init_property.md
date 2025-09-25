## Description

The **ACX_REQUEST_PARAMETERS_INIT_PROPERTY** initializes an ACX_REQUEST_PARAMETERS struct with ACX property parameters.

## Parameters

### `Params`

A pointer to [ACX_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_request_parameters) structure that is used to store property parameters.

### `Set`

A property Set ID (GUID).

### `Id`

A property ID (ULONG) within the property Set ID.

### `Verb`

The ACX property verb to send as defined by the [ACX_PROPERTY_VERB](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_property_verb) enumeration.

### `ItemType`

The [ACX_ITEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_item_type) type of item being sent, for example AcxItemTypeCircuit.

### `ItemId`

The item ID of the ItemType, for example the pin ID if the ItemType is a pin.

### `Control`

An optional Control buffer holding additional parameters for the specified property. Set to null if not present.

### `ControlCb`

The count in bytes (size) of the Control buffer. Set to 0 if Control field is not used.

### `Value`

An optional Value buffer to specify or receive the property's value. Set to null if not present or if *SendProperty needs to allocate it when ValueCb is not zero. Caller is responsible for freeing the allocated buffer.

### `ValueCb`

The count in bytes (size) of the Value buffer. Set to 0 if Value is not used.

## Remarks

### Example

Example usage is shown below.

```cpp

    NTSTATUS                    status = STATUS_SUCCESS;
    PKSPIN_PHYSICALCONNECTION   physicalConnection = nullptr;
    PAUDIO_PATH_DESCRIPTOR      descriptor = nullptr;

    // For the Audio Circuit, send a request to each Target Pin asking KSPROPERTY_PIN_PHYSICALCONNECTION
    // This will give us symbolic link of the next circuit in the Audio Path (if there is any)

    for (ULONG i = 0; i < ARRAYSIZE(AudioCircuit->Pins) && AudioCircuit->Pins[i].TargetPin; ++i)
    {
        ACX_REQUEST_PARAMETERS requestParams{ 0 };

        ACX_REQUEST_PARAMETERS_INIT_PROPERTY(
            &requestParams,
            KSPROPSETID_Pin,
            KSPROPERTY_PIN_PHYSICALCONNECTION,
            AcxPropertyVerbGet,
            AcxItemTypePin,
            i,
            nullptr,
            0,
            // null Value so SendProperty will allocate it for us. We'll need to free it.
            nullptr,
            0);
...

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)