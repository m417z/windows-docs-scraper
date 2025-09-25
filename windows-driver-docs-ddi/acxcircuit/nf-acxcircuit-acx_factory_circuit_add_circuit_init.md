## Description

The **ACX_FACTORY_CIRCUIT_ADD_CIRCUIT_INIT** function initializes a [ACX_FACTORY_CIRCUIT_ADD_CIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_add_circuit) structure. No inputs are used with this function.

## Parameters

### `Parameters`

An initialized [ACX_FACTORY_CIRCUIT_ADD_CIRCUIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ns-acxcircuit-acx_factory_circuit_add_circuit) structure that is used to store circuit information.

## Remarks

### Example

Example usage is shown below.

```cpp

    ACX_FACTORY_CIRCUIT_ADD_CIRCUIT addParams;

    ACX_FACTORY_CIRCUIT_ADD_CIRCUIT_INIT(&addParams);
    addParams.CircuitUniqueId = m_CircuitUniqueId;

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)