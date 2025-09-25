## Description

The **ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS** structure contains pointers to an ACXFACTORYCIRCUIT's Plug and Play and power event callback functions.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtAcxFactoryCircuitPrepareHardware`

A pointer to the driver's [ACX_FACTORY_CIRCUIT_PREPARE_HARDWARE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_prepare_hardware) event callback function, or NULL.

### `EvtAcxFactoryCircuitReleaseHardware`

A pointer to the driver's [ACX_FACTORY_CIRCUIT_RELEASE_HARDWARE callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_release_hardware) event callback function, or NULL.

### `EvtAcxFactoryCircuitPowerUp`

A pointer to the [ACX_FACTORY_CIRCUIT_POWER_UP callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_power_up) event callback function, or NULL.

### `EvtAcxFactoryCircuitPowerDown`

A pointer to the [ACX_FACTORY_CIRCUIT_POWER_DOWN callback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nc-acxcircuit-evt_acx_factory_circuit_power_down) event callback function, or NULL.

## Remarks

The ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS structure is used as input to the [AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitsetacxcircuitpnppowercallbacks) method.

Your driver should initialize its ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS structure by calling the [ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acx_factory_circuit_pnppower_callbacks_init) function.

### Example

Example usage is shown below.

```cpp
    //
    // Assign the factory circuit's pnp-power callbacks.
    //
    ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS powerCallbacks;
    ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS_INIT(&powerCallbacks);
    powerCallbacks.EvtAcxFactoryCircuitPowerUp = EvtFactoryCircuitPowerUp;
    powerCallbacks.EvtAcxFactoryCircuitPowerDown = EvtFactoryCircuitPowerDown;
    AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks(factoryInit, &powerCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)
- [AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitsetacxcircuitpnppowercallbacks)