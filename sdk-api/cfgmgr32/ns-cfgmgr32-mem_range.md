# MEM_RANGE structure

## Description

The MEM_RANGE structure specifies a resource requirements list that describes memory usage for a device instance. For more information about resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `MR_Align`

Mask used to specify the memory address boundary on which the first allocated memory address must be aligned.

### `MR_nBytes`

The number of bytes of memory required by the device.

### `MR_Min`

The lowest-numbered of a range of contiguous memory addresses that can be allocated to the device.

### `MR_Max`

The highest-numbered of a range of contiguous memory addresses that can be allocated to the device.

### `MR_Flags`

One bit flag from [MEM_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_des) structure.

### `MR_Reserved`

*For internal use only.*

## See also

[MEM_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_des)