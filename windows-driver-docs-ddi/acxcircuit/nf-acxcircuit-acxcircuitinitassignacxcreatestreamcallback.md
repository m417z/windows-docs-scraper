## Description

The **AcxCircuitInitAssignAcxCreateStreamCallback** function is used to assign an ACX create stream callback.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `EvtCircuitCreateStream`

A pointer to a [EVT_ACX_CIRCUIT_CREATE_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_circuit_create_stream) callback.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp

    //
    // Get a CircuitInit structure.
    //
    circuitInit = AcxCircuitInitAllocate(Device);

    //
    // Assign the circuit's pnp-power callbacks.
    //
    ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT(&powerCallbacks);
    powerCallbacks.EvtAcxCircuitPowerUp = CodecC_EvtCircuitPowerUp;
    powerCallbacks.EvtAcxCircuitPowerDown = CodecC_EvtCircuitPowerDown;
    AcxCircuitInitSetAcxCircuitPnpPowerCallbacks(circuitInit, &powerCallbacks);

    //
    // Set circuit-callbacks.
    //
    status = AcxCircuitInitAssignAcxRequestPreprocessCallback(
                                            circuitInit,
                                            CodecC_EvtCircuitRequestPreprocess,
                                            (ACXCONTEXT)AcxRequestTypeAny, // dbg only
                                            AcxRequestTypeAny,
                                            NULL,
                                            AcxItemIdNone);

    status = AcxCircuitInitAssignAcxCreateStreamCallback(
                                            circuitInit,
                                            CodecC_EvtCircuitCreateStream);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)