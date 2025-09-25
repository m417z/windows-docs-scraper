# DMA_DES structure

## Description

The DMA_DES structure is used for specifying either a resource list or a resource requirements list that describes direct memory access (DMA) channel usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `DD_Count`

#### For a resource list:

Zero.

#### For a resource requirements list:

The number of elements in the [DMA_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_resource) structure.

### `DD_Type`

Must be set to the constant value **DType_Range**.

### `DD_Flags`

One bit flag from *each* of the flag sets described in the following table.

|  | Flag | Definition |
| --- | --- | --- |
| *Channel Width Flags* | |  |
|  | **fDD_BYTE** | 8-bit DMA channel. |
|  | **fDD_WORD** | 16-bit DMA channel. |
|  | **fDD_DWORD** | 32-bit DMA channel. |
|  | **fDD_BYTE_AND_WORD** | 8-bit and 16-bit DMA channel. |
|  | **mDD_Width** | Bitmask for the bits within **DD_Flags** that specify the channel width value. |
| *Bus Mastering Flags* | |  |
|  | **fDD_NoBusMaster** | No bus mastering. |
|  | **fDD_BusMaster** | Bus mastering. |
|  | **mDD_BusMaster** | Bitmask for the bits within **DD_Flags** that specify the bus mastering value. |
| *DMA Type Flags* | |  |
|  | **fDD_TypeStandard** | Standard DMA. |
|  | **fDD_TypeA** | Type A DMA. |
|  | **fDD_TypeB** | Type B DMA. |
|  | **fDD_TypeF** | Type F DMA. |
|  | **mDD_Type** | Bitmask for the bits within **DD_Flags** that specify the DMA type value. |

### `DD_Alloc_Chan`

#### For a resource list:

The DMA channel allocated to the device.

#### For a resource requirements list:

*Not used.*

## See also

[DMA_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_range)

[DMA_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-dma_resource)