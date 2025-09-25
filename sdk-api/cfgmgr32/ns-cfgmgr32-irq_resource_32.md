# IRQ_RESOURCE_32 structure

## Description

The IRQ_RESOURCE structure is used for specifying either a resource list or a resource requirements list that describes IRQ line usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `IRQ_Header`

An [IRQ_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_des_32) structure.

### `IRQ_Data`

#### For a resource list:

Zero.

#### For a resource requirements list:

An [IRQ_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_range) array.

## See also

[IRQ_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_des_32)

[IRQ_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_range)