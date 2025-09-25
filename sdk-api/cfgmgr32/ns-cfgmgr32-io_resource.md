# IO_RESOURCE structure

## Description

The IO_RESOURCE structure is used for specifying either a resource list or a resource requirements list that describes I/O port usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `IO_Header`

An [IO_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_des) structure.

### `IO_Data`

#### For a resource list:

Zero.

#### For a resource requirements list:

An [IO_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_range) array.

## See also

[IO_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_des)

[IO_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-io_range)