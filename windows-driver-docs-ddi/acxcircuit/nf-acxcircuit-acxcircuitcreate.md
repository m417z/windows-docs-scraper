## Description

The **AcxCircuitCreate** function is used to create an ACXCIRCUIT.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that will be associated with the circuit.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) that are used to set the various object's values: cleanup and destroy callbacks, context type, and to specify its parent WDF object.

### `Config`

The ACXCIRCUIT_INIT structure that defines the circuit factory initialization. ACXCIRCUIT_INIT is an opaque object used for circuit factory initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `Circuit`

A pointer to a location that receives a handle to the new ACXCIRCUIT Object. For more information, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An ACXCIRCUIT represents a full or partial (multi-circuit) audio path to a user perceived audio device (speakers, mic, etc.).

An ACXCIRCUIT has at least one input pin (ACXPIN) and one output pin (ACXPIN), and it may aggregate one or more ACXELEMENTS objects. By default, ACXELEMENTs are 'connected' in the same order of assembly.

### Example

Example usage is shown below.

```cpp
    status = AcxCircuitInitAssignName(circuitInit, &circuitName);
    //
    // Add circuit type.
    //
    AcxCircuitInitSetCircuitType(circuitInit, AcxCircuitTypeRender);

    //
    // Assign the circuit's pnp-power callbacks.
    //
    ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT(&powerCallbacks);
    powerCallbacks.EvtAcxCircuitPowerUp = SdcaR_EvtCircuitPowerUp;
    powerCallbacks.EvtAcxCircuitPowerDown = SdcaR_EvtCircuitPowerDown;

    AcxCircuitInitSetAcxCircuitPnpPowerCallbacks(circuitInit, &powerCallbacks);

    //
    // Set circuit-callbacks.
    //
    status = AcxCircuitInitAssignAcxCreateStreamCallback(
                                            circuitInit,
                                            SdcaR_EvtCircuitCreateStream);

    //
    // Create the circuit.
    //
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, SDCA_RENDER_CIRCUIT_CONTEXT);
    status = AcxCircuitCreate(Device, &attributes, &circuitInit, &circuit);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)