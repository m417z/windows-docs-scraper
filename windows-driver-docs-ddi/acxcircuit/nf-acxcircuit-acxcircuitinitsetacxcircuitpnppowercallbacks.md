## Description

The **AcxCircuitInitSetAcxCircuitPnpPowerCallbacks** function sets the driver's PNP callbacks for the ACXCIRCUIT.

## Parameters

### `CircuitInit`

The ACXCIRCUIT_INIT structure that defines the circuit initialization. ACXCIRCUIT_INIT is an opaque object used for circuit initialization. Use [AcxCircuitInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitallocate) to initialize the ACXCIRCUIT_INIT structure.

### `EvtPnpPowerCallbacks`

An [ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_pnppower_callbacks) PnP power callbacks structure that defines the callbacks.

## Remarks

Before calling AcxCircuitInitSetAcxCircuitPnpPowerCallbacks, your driver should initialize its ACX_CIRCUIT_PNPPOWER_CALLBACKS structure by calling [ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acx_circuit_pnppower_callbacks_init). The ACX_CIRCUIT_PNPPOWER_CALLBACKS structure is used as input to the `AcxCircuitInitSetAcxCircuitPnpPowerCallbacks method`.

### Example

Example usage is shown below.

```cpp
    //
    // Assign the circuit's pnp-power callbacks.
    //
    ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT(&powerCallbacks);
    powerCallbacks.EvtAcxCircuitPowerUp = CodecR_EvtCircuitPowerUp;
    powerCallbacks.EvtAcxCircuitPowerDown = CodecR_EvtCircuitPowerDown;
    AcxCircuitInitSetAcxCircuitPnpPowerCallbacks(circuitInit, &powerCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)