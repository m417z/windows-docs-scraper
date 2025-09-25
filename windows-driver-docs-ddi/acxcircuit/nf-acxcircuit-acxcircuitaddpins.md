## Description

The **AcxCircuitAddPins** function adds pins to an ACXCIRCUIT.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Pins`

An existing ACXPIN object that will be added to the circuit.

### `PinsCount`

The number of pins that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An ACXCIRCUIT has at least an input pin (ACXPIN) and an output pin (ACXPIN), and it may aggregate one or more ACXELEMENTs.

Each ACXCIRCUIT has at least one Sink pin and one Source pin. These pins are used by the ACX framework to expose the circuit's connections to the audio stack. For a Render circuit, the Source pin is used to control the render behavior (device properties) of any stream created from the circuit. For a Capture circuit, the Sink pin is used to control the capture behavior (device properties) of any stream created from the circuit.

ACXPIN is the object used to control streaming in the Audio Path. For simple ACXCIRCUIT topologies, ACX is able to automatically create the other ACXPIN if only one is present.

### Example

Example usage is shown below.

```cpp
    ACXPIN pin;

    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.ParentObject = circuit;

    status = AcxPinCreate(circuit, &attributes, &pinCfg, &(pin[1]));

    // Add the supported formats to the Default mode for the circuit
    //
    formatList = AcxPinGetRawDataFormatList(pin[1]);

    status = AcxDataFormatListAddDataFormat(formatList, formatPcm16000c1);

    //
    // Add the default streaming pin, using default pin id.
    //
    status = AcxCircuitAddPins(circuit, &(pin[1]), 1);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)