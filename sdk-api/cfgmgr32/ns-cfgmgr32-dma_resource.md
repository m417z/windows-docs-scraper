# DMA_RESOURCE structure

## Description

The DMA_RESOURCE structure is used for specifying either a resource list or a resource requirements list that describes DMA channel usage for a device instance. For more information about resource list and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `DMA_Header`

A [DMA_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_des) structure.

### `DMA_Data`

#### For a resource list:

Zero.

#### For a resource requirements list:

A [DMA_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_range) array.

## See also

[DMA_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_des)

[DMA_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_range)