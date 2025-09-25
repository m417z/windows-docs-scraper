# BUSNUMBER_RANGE structure

## Description

The BUSNUMBER_RANGE structure specifies a resource requirements list that describes bus number usage for a device instance. For more information about resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `BUSR_Min`

The lowest-numbered of a range of contiguous bus numbers that can be allocated to the device.

### `BUSR_Max`

The highest-numbered of a range of contiguous bus numbers that can be allocated to the device.

### `BUSR_nBusNumbers`

The number of contiguous bus numbers required by the device.

### `BUSR_Flags`

*Not used.*

## Remarks

The BUSNUMBER_RANGE structure is included as a member of the [BUSNUMBER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_resource) structure.

## See also

[BUSNUMBER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-busnumber_resource)