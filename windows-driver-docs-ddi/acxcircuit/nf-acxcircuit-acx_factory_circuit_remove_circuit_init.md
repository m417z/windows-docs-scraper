## Description

The **ACX_FACTORY_CIRCUIT_REMOVE_CIRCUIT_INIT** function initializes a [ACX_FACTORY_CIRCUIT_REMOVE_CIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_remove_circuit) structure. No inputs are used with this function.

## Parameters

### `Parameters`

A pointer to a [ACX_FACTORY_CIRCUIT_REMOVE_CIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_remove_circuit) structure that will be initialized.

## Remarks

NOTE: internal only, do not use.

### Example

Example usage is shown below.

```cpp
    ACX_FACTORY_CIRCUIT_REMOVE_CIRCUIT  remParams;

    m_CircuitRequested = false;

    ACX_FACTORY_CIRCUIT_REMOVE_CIRCUIT_INIT(&remParams);
    remParams.CircuitUniqueId = m_CircuitUniqueId;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)