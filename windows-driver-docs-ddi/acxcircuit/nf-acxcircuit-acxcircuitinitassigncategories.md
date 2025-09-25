## Description

The **AcxCircuitInitAssignCategories** function assigns a set of KSCATERGORY entries for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `Categories`

An array that contains GUIDS of the desired KSCATERGORY, for example `KSCATEGORY_AUDIO`. For more information about the KSCATERGORY entries, see [Installing Device Interfaces for an Audio Adapter](https://learn.microsoft.com/windows-hardware/drivers/audio/installing-device-interfaces-for-an-audio-adapter).

### `CategoriesCount`

The number of categories that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

This call overrides the default category set initialized by ACX which is based on the ACXCIRCUIT type.

### Example

Example usage is shown below.

```cpp

    GUID captureCategories[] =
    {
        STATICGUIDOF(KSCATEGORY_AUDIO),
        STATICGUIDOF(KSCATEGORY_CAPTURE),
        STATICGUIDOF(KSCATEGORY_REALTIME),
        STATICGUIDOF(KSCATEGORY_TOPOLOGY),
    };

    //
    // Add circuit identifiers.
    //
    AcxCircuitInitSetComponentId(CircuitInit, &COMPONENT_GUID);

    AcxCircuitInitAssignName(CircuitInit, &circuitName);

    status = AcxCircuitInitAssignCategories(CircuitInit, captureCategories, SIZEOF_ARRAY(captureCategories));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)