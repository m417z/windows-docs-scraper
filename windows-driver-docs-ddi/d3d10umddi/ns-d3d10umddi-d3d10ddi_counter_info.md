# D3D10DDI_COUNTER_INFO structure

## Description

The D3D10DDI_COUNTER_INFO structure describes information to manipulate counters.

## Members

### `LastDeviceDependentCounter` [out]

A [D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)-typed value that identifies the largest device-dependent counter identifier that the device supports. If none are supported, the user-mode display driver must set the value to 0; otherwise, the driver sets the value to greater than or equal to D3D10DDI_COUNTER_DEVICE_DEPENDENT_0 (0x40000000).

### `NumSimultaneousCounters` [out]

The number of simultaneously active counters that the driver supports.

### `NumDetectableParallelUnits` [out]

The number of detectable parallel units that the counters can identify. Valid values are from 1 through 4.

## See also

[CheckCounterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounterinfo)

[D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)