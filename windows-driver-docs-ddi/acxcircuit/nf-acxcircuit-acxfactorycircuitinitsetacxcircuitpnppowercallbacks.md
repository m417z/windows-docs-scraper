## Description

The AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks function sets the driver's PNP callbacks for the ACXFACTORYCIRCUIT.

## Parameters

### `FactoryInit`

An ACXFACTORYCIRCUIT_INIT structure that is used for circuit factory initialization. This is an opaque structure that is used to store ACX Circuit factory initialization information and associate the factory with a WDF device.

Use the [AcxFactoryCircuitInitAllocate function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxfactorycircuitinitallocate) to initialize the ACXFACTORYCIRCUIT_INIT structure.

### `EvtPnpPowerCallbacks`

An [ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_pnppower_callbacks) power callbacks structure that defines the callbacks.

## Remarks

NOTE: At this time this DDI is not supported. Do not use it at this time.

Before calling AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks, your driver should initialize its ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS structure by calling [ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acx_factory_circuit_pnppower_callbacks_init). The ACX_FACTORY_CIRCUIT_PNPPOWER_CALLBACKS structure is used as input to the `AcxFactoryCircuitInitSetAcxCircuitPnpPowerCallbacks method`.

### Example

Example usage is shown below.

```cpp
    // Get a FactoryCircuitInit structure.
    //
    factoryInit = AcxFactoryCircuitInitAllocate(Device);

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