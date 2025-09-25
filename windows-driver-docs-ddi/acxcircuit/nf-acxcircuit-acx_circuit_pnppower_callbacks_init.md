## Description

The **ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT** function initializes a [ACX_CIRCUIT_PNPPOWER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_circuit_pnppower_callbacks). No inputs are used with this function.

## Parameters

### `PnpPowerCallbacks`

A pointer to an initialized [ACX_CIRCUIT_PNPPOWER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_circuit_pnppower_callbacks).

## Remarks

### Example

Example usage is shown below.

```cpp
      //
    // Add circuit identifiers.
    //
    AcxCircuitInitSetComponentId(CircuitInit, &COMPONENT_GUID);

    AcxCircuitInitAssignName(CircuitInit, &circuitName);

    //
    // Add circuit type.
    //
    AcxCircuitInitSetCircuitType(CircuitInit, AcxCircuitTypeRender);

    //
    // Assign the circuit's pnp-power callbacks.
    //
    {
        ACX_CIRCUIT_PNPPOWER_CALLBACKS  powerCallbacks;
        ACX_CIRCUIT_PNPPOWER_CALLBACKS_INIT(&powerCallbacks);
        powerCallbacks.EvtAcxCircuitPowerUp = R_EvtCircuitPowerUp;
        powerCallbacks.EvtAcxCircuitPowerDown = R_EvtCircuitPowerDown;
        AcxCircuitInitSetAcxCircuitPnpPowerCallbacks(CircuitInit, &powerCallbacks);
    }
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)