## Description

The **ACX_CIRCUIT_PNPPOWER_CALLBACKS** structure contains pointers to an ACXCIRCUIT's Plug and Play and power event callback.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtAcxCircuitPrepareHardware`

A pointer to the driver's [ACX_CIRCUIT_PREPARE_HARDWARE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_prepare_hardware) event callback function, or NULL.

### `EvtAcxCircuitReleaseHardware`

A pointer to the driver's [ACX_CIRCUIT_RELEASE_HARDWARE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_release_hardware) event callback function, or NULL.

### `EvtAcxCircuitPowerUp`

A pointer to the [ACX_CIRCUIT_POWER_UP callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_power_up) event callback function, or NULL.

### `EvtAcxCircuitPowerDown`

A pointer to the [ACX_CIRCUIT_POWER_DOWN callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_power_down) event callback function, or NULL.

## Remarks

The ACX_CIRCUIT_PNPPOWER_CALLBACKS structure is used as input to the [AcxCircuitInitSetAcxCircuitPnpPowerCallbacks method](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitsetacxcircuitpnppowercallbacks).

Your driver should initialize its ACX_CIRCUIT_PNPPOWER_CALLBACKS structure by calling [ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acx_circuit_pnppower_callbacks_init).

### Example

Example usage is shown below.

```cpp
    //
    // Assign the circuit's pnp-power callbacks.
    //
    {
        ACX_CIRCUIT_PNPPOWER_CALLBACKS  powerCallbacks;
        ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT(&powerCallbacks);
        powerCallbacks.EvtAcxCircuitPowerUp = EvtCircuitPowerUp;
        powerCallbacks.EvtAcxCircuitPowerDown = EvtCircuitPowerDown;
        AcxCircuitInitSetAcxCircuitPnpPowerCallbacks(CircuitInit, &powerCallbacks);
    }

    status = AcxCircuitInitAssignAcxCreateStreamCallback(CircuitInit, EvtCircuitCreateStream);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

[ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acx_circuit_pnppower_callbacks_init)

[AcxCircuitInitSetAcxCircuitPnpPowerCallbacks method](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitsetacxcircuitpnppowercallbacks)

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)