## Description

The **ACX_FACTORY_CIRCUIT_ADD_CIRCUIT** structure is used to add circuits by an ACX circuit factory.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Bitwise OR of [ACX_FACTORY_CIRCUIT_ADD_CIRCUIT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ne-acxcircuit-acx_factory_circuit_add_circuit_flags).

### `CircuitUniqueId`

A GUID that is used to uniquely identify the circuit.

### `CompositeProperties`

Optional handle to CompositeProperties.

### `FactoryProperties`

Optional handle to FactoryProperties.

### `CircuitProperties`

Optional handle to CircuitProperties

### `TargetSymbolicLinkName`

Optional string that provides the target symbolic link name.

## Remarks

ACX Manager initializes and sends this structure to an ACXFACTORYCIRCUIT when a new ACXCIRCUIT object is needed. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

Drivers receive this structure in their ACXFACTORYCIRCUIT's callback as a passing parameter.

### Example

Example pending.

```cpp

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)