## Description

The **ACX_CIRCUIT_TEMPLATE_CONFIG** structure is used to configure a new ACX circuit template object.

## Members

### `Size`

The size of all of the data in the **ACX_CIRCUIT_TEMPLATE_CONFIG** structure in bytes. This field is set by the [ACX_CIRCUIT_TEMPLATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/nf-acxmanager-acx_circuit_template_config_init) function.

### `Flags`

A combination of values from the [ACX_CIRCUIT_TEMPLATE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/ne-acxmanager-acx_circuit_template_config_flags) enum that describe the circuit template.

### `ContainerId`

An optional GUID that specifies the ID of the circuit container.

### `FactoryProperties`

An **ACXOBJECTBAG** with the factory properties for the circuit-on-demand option.

### `FactoryId`

The GUID value of the factory circuit ID. Mutually exclusive with *FactoryUri*.

### `FactoryUri`

A Unicode string containing the fully qualified factory resource ID. Mutually exclusive with the *FactoryId*.

### `FactoryName`

Set to `NULL`.

### `CircuitProperties`

An **ACXOBJECTBAG** with the circuit properties for the *not* circuit-on-demand option.

### `CircuitId`

The GUID value of the circuit ID. Mutually exclusive with *CircuitUri*.

### `CircuitUri`

A Unicode string containing the fully qualified circuit resource ID. Mutually exclusive with the *CircuitId*.

### `CircuitName`

Set to `NULL`.

## Remarks

The **ACX_CIRCUIT_TEMPLATE_CONFIG** structure is initialized by calling the [ACX_CIRCUIT_TEMPLATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/nf-acxmanager-acx_circuit_template_config_init) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_CIRCUIT_TEMPLATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/nf-acxmanager-acx_circuit_template_config_init)
- [ACX_CIRCUIT_TEMPLATE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/ne-acxmanager-acx_circuit_template_config_flags)
- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)