# PCCARD_DES structure

## Description

The PCCARD_DES structure is used for specifying either a resource list or a resource requirements list that describes resource usage by a PC Card instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `PCD_Count`

Must be 1.

### `PCD_Type`

*Not used.*

### `PCD_Flags`

One bit flag from *each* of the flag sets described in the following table.

|  | Flag | Definition |
| --- | --- | --- |
| *I/O Addressing Flags* | |  |
|  | fPCD_IO_8 | The device uses 8-bit I/O addressing. |
|  | fPCD_IO_16 | The device uses 16-bit I/O addressing. |
|  | mPCD_IO_8_16 | Bitmask for the bit within **PCD_Flags** that specifies 8-bit or 16-bit I/O addressing. |
| *Memory Addressing Flags* | |  |
|  | fPCD_MEM_8 | The device uses 8-bit memory addressing. |
|  | fPCD_MEM_16 | The device uses 16-bit memory addressing. |
|  | mPCD_MEM_8_16 | Bitmask for the bit within **PCD_Flags** that specifies 8-bit or 16-bit memory addressing. |

### `PCD_ConfigIndex`

The 8-bit index value used to locate the device's configuration.

### `PCD_Reserved`

*Not used.*

### `PCD_MemoryCardBase1`

*Optional*, card base address of the first memory window.

### `PCD_MemoryCardBase2`

*Optional*, card base address of the second memory window.

### `PCD_MemoryCardBase`

This member is currently unused.

### `PCD_MemoryFlags`

This member is currently unused.

### `PCD_IoFlags`

This member is currently unused.

## See also

[PCCARD_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-pccard_resource)