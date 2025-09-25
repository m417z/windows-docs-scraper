## Description

The **AcxCircuitInitAssignProperties** function assigns one or more ACX properties for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `Properties`

An [ACX_PROPERTY_ITEM structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_property_item) that defines a set of properties that will be used for circuit initialization by the circuit factory.

### `PropertiesCount`

The number of properties that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

Drivers should only add driver owned properties.

### Example

Example usage is shown below.

```cpp

    PACXCIRCUIT_INIT circuitInit = NULL;
    circuitInit = AcxCircuitInitAllocate(Device);

    ACX_PROPERTY_ITEM CircuitProperties[] =
    {
        {
            &KSPROPSETID_AudioPosture,
            KSPROPERTY_AUDIOPOSTURE_ORIENTATION,
            KSPROPERTY_TYPE_SET,
            EvtCircuitPropertyHandler,
            nullptr,                            //Reserved
            0,                                  //ControlCb
            sizeof(AUDIOPOSTURE_ORIENTATION),   //ValueCb
        },
    };

    status = AcxCircuitInitAssignProperties(circuitInit,
        CircuitProperties,
        SIZEOF_ARRAY(CircuitProperties));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)