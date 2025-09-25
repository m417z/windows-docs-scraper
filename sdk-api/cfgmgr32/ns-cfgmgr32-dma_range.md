# DMA_RANGE structure

## Description

The DMA_RANGE structure specifies a resource requirements list that describes DMA channel usage for a device instance. For more information about resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `DR_Min`

The lowest-numbered DMA channel that can be allocated to the device.

### `DR_Max`

The highest-numbered DMA channel that can be allocated to the device.

### `DR_Flags`

One bit flag from [DMA_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_des) structure.

## See also

[DMA_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_des)