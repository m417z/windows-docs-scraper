# BUSNUMBER_RESOURCE structure

## Description

The BUSNUMBER_RESOURCE structure specifies either a resource list or a resource requirements list that describes bus number usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `BusNumber_Header`

A [BUSNUMBER_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_des) structure.

### `BusNumber_Data`

#### For a resource list:

Zero.

#### For a resource requirements list:

A [BUSNUMBER_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_range) array.

## See also

[BUSNUMBER_DES](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_des)

[BUSNUMBER_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_range)