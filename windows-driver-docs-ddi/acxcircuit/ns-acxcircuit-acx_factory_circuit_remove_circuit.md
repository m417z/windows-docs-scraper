## Description

The **ACX_FACTORY_CIRCUIT_REMOVE_CIRCUIT** structure is used to remove ACX circuit factory circuits.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Bitwise OR of [ACX_FACTORY_CIRCUIT_REMOVE_CIRCUIT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ne-acxcircuit-acx_factory_circuit_remove_circuit_flags)

### `CircuitUniqueId`

A GUID that is used to uniquely identify the circuit.

## Remarks

ACX Manager initializes and sends this structure to an ACXFACTORYCIRCUIT when an existing ACXCIRCUIT object must be removed.

Drivers receive this structure in their ACXFACTORYCIRCUIT's callback as passing parameter.

For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### Example

Example pending.

```cpp

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)