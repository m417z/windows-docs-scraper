# IRQ_RANGE structure

## Description

The IRQ_RANGE structure specifies a resource requirements list that describes IRQ line usage for a device instance. For more information about resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `IRQR_Min`

The lowest-numbered of a range of contiguous IRQ lines that can be allocated to the device.

### `IRQR_Max`

The highest-numbered of a range of contiguous IRQ lines that can be allocated to the device.

### `IRQR_Rsvdz`

### `IRQR_Flags`

One bit flag from [IRQ_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_des_32) structure.

## See also

[IRQ_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_des_32)