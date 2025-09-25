## Description

This enumeration is used in the [**POOL_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_extended_parameter) structure.

## Constants

### `PoolExtendedParameterInvalidType:0`

Invalid extended parameter type. Do not use.

### `PoolExtendedParameterPriority`

The extended parameter specifies the priority of the pool allocation using the **Priority** field of the [**POOL_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_extended_parameter) structure.

### `PoolExtendedParameterSecurePool`

The extended parameter specifies the secure pool parameters of the pool allocation using the **SecurePoolParams** field of the [**POOL_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_extended_parameter) structure.

### `PoolExtendedParameterNumaNode`

The extended parameter specifies the preferred NUMA node of the pool allocation using the **PreferredNode** field of the [**POOL_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_extended_parameter) structure.

### `PoolExtendedParameterMax`

For internal use only.

## Remarks

## See also

[**ExAllocatePool3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool3)