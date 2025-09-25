# _NDIS_MSIX_TABLE_CONFIG enumeration

## Description

The NDIS_MSIX_TABLE_OPERATION enumeration identifies the type of MSI-X configuration
operation.

## Constants

### `NdisMSIXTableConfigSetTableEntry`

The MSI-X table entry should be mapped to an MSI-X message that the bus driver allocated to the
device.

### `NdisMSIXTableConfigMaskTableEntry`

The interrupts from an MSI-X table entry source should be masked.

### `NdisMSIXTableConfigUnmaskTableEntry`

The interrupts from an MSI-X table entry source should be unmasked.

### `NdisMSIXTableConfigMax`

The number of enumeration values in NDIS_MSIX_TABLE_OPERATION.

## Remarks

The NDIS_MSIX_TABLE_OPERATION enumeration is used in the
[NDIS_MSIX_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_msix_config_parameters) structure.

## See also

[NDIS_MSIX_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_msix_config_parameters)