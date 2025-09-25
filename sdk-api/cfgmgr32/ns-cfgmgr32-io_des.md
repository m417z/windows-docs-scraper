# IO_DES structure

## Description

The IO_DES structure is used for specifying either a resource list or a resource requirements list that describes I/O port usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `IOD_Count`

#### For a resource list:

Zero.

#### For a resource requirements list:

The number of elements in the [IO_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_range) array that is included in the [IO_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_resource) structure.

### `IOD_Type`

Must be set to the constant value **IOType_Range**.

### `IOD_Alloc_Base`

#### For a resource list:

The lowest-numbered of a range of contiguous I/O port addresses allocated to the device.

#### For a resource requirements list:

Zero.

### `IOD_Alloc_End`

#### For a resource list:

The highest-numbered of a range of contiguous I/O port addresses allocated to the device.

#### For a resource requirements list:

Zero.

### `IOD_DesFlags`

One bit flag from *each* of the flag sets described in the following table.

|  | Flag | Definition |
| --- | --- | --- |
| *Port Type Flags* | |  |
|  | **fIOD_IO** | The device is accessed in I/O address space. |
|  | **fIOD_Memory** | The device is accessed in memory address space. |
|  | **fIOD_PortType** | Bitmask for the bits within **IOD_DesFlags** that specify the port type value. |
| *Decode Flags* | |  |
|  | **fIOD_10_BIT_DECODE** | The device decodes 10 bits of the port address. |
|  | **fIOD_12_BIT_DECODE** | The device decodes 12 bits of the port address. |
|  | **fIOD_16_BIT_DECODE** | The device decodes 16 bits of the port address. |
|  | **fIOD_POSITIVE_DECODE** | The device uses "positive decode" instead of "subtractive decode." |
|  | **fIOD_DECODE** | Bitmask for the bits within **IOD_DesFlags** that specify the decode value. |

## See also

[IO_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_range)

[IO_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_resource)