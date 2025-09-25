# BUSNUMBER_DES structure

## Description

The BUSNUMBER_DES structure is used for specifying either a resource list or a resource requirements list that describes bus number usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `BUSD_Count`

#### For a resource list:

Zero.

#### For a resource requirements list:

The number of elements in the [BUSNUMBER_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_range) array that is included in the [BUSNUMBER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_resource) structure.

### `BUSD_Type`

Must be set to the constant value **BusNumberType_Range**.

### `BUSD_Flags`

*Not used.*

### `BUSD_Alloc_Base`

#### For a resource list:

The lowest-numbered of a range of contiguous bus numbers allocated to the device.

#### For a resource requirements list:

Zero.

### `BUSD_Alloc_End`

#### For a resource list:

The highest-numbered of a range of contiguous bus numbers allocated to the device.

#### For a resource requirements list:

Zero.

## Remarks

The BUSNUMBER_DES structure is included as a member of the [BUSNUMBER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_resource) structure.

## See also

[BUSNUMBER_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_range)

[BUSNUMBER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_resource)