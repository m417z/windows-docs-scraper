# MEM_RESOURCE structure

## Description

The MEM_RESOURCE structure is used for specifying either a resource list or a resource requirements list that describes memory usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `MEM_Header`

A [MEM_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_des) structure.

### `MEM_Data`

#### For a resource list:

Zero.

#### For a resource requirements list:

A [MEM_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_range) array.

## See also

[MEM_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_des)

[MEM_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_range)