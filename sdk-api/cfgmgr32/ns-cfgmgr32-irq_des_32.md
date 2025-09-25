# IRQ_DES_32 structure

## Description

The IRQ_DES structure is used for specifying either a resource list or a resource requirements list that describes IRQ line usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `IRQD_Count`

#### For a resource list:

Zero.

#### For a resource requirements list:

The number of elements in the [IRQ_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_range) array that is included in the [IRQ_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_resource_32) structure.

### `IRQD_Type`

Must be set to the constant value **IRQType_Range**.

### `IRQD_Group`

### `IRQD_Flags`

One bit flag from *each* of the flag sets described in the following table.

|  | Flag | Definition |
| --- | --- | --- |
| *Sharing Flags* | |  |
|  | **fIRQD_Exclusive** | The IRQ line cannot be shared. |
|  | **fIRQD_Share** | The IRQ line can be shared. |
|  | **mIRQD_Share** | Bitmask for the bits within **IRQD_Flags** that specify the sharing value. |
| *Triggering Flags* | |  |
|  | **fIRQD_Level** | The IRQ line is level-triggered. |
|  | **fIRQD_Edge** | The IRQ line is edge-triggered. |
|  | **mIRQD_Edge_Level** | Bitmask for the bits within **IRQD_Flags** that specify the triggering value. |

### `IRQD_Alloc_Num`

#### For a resource list:

The number of the IRQ line that is allocated to the device.

#### For a resource requirements list:

*Not used.*

### `IRQD_Affinity`

#### For a resource list:

A bitmask representing the processor affinity of the IRQ line that is allocated to the device. Bit zero represents the first processor, bit two the second, and so on. Set this value to -1 to represent all processors.

#### For a resource requirements list:

*Not used.*

## See also

[IRQ_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_range)

[IRQ_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-irq_resource_32)