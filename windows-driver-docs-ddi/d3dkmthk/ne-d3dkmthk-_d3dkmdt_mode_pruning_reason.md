# _D3DKMDT_MODE_PRUNING_REASON enumeration

## Description

The D3DKMDT_MODE_PRUNING_REASON enumeration type contains values that identify the reason why the monitor either supports a display mode or does not support a display mode.

## Constants

### `D3DKMDT_MPR_UNINITIALIZED`

A variable of type D3DKMDT_MODE_PRUNING_REASON has not yet been assigned a meaningful value.

### `D3DKMDT_MPR_ALLCAPS`

The monitor does not support the display mode because none of the available monitor capabilities imply support of the display mode.

### `D3DKMDT_MPR_DESCRIPTOR_MONITOR_SOURCE_MODE`

The monitor supports the display mode because of the monitor source mode in the monitor descriptor.

### `D3DKMDT_MPR_DESCRIPTOR_MONITOR_FREQUENCY_RANGE`

The monitor does not support the display mode because of the monitor frequency range in the monitor descriptor.

### `D3DKMDT_MPR_DESCRIPTOR_OVERRIDE_MONITOR_SOURCE_MODE`

The monitor supports the display mode because of the monitor source mode in the monitor descriptor override.

### `D3DKMDT_MPR_DESCRIPTOR_OVERRIDE_MONITOR_FREQUENCY_RANGE`

The monitor does not support the display mode because of the monitor frequency range in the monitor descriptor override.

### `D3DKMDT_MPR_DEFAULT_PROFILE_MONITOR_SOURCE_MODE`

The monitor supports the display mode because of the monitor source mode in the default monitor profile.

### `D3DKMDT_MPR_DRIVER_RECOMMENDED_MONITOR_SOURCE_MODE`

The monitor supports the display mode because of the monitor source mode that the display miniport driver recommends.

### `D3DKMDT_MPR_MONITOR_FREQUENCY_RANGE_OVERRIDE`

The monitor supports the display mode because of the monitor frequency range override.

### `D3DKMDT_MPR_CLONE_PATH_PRUNED`

Supported in Windows 7 and later versions.

The display mode is pruned (that is, the monitor does not support the display mode) because other paths in the clone cluster have no mode supported by the monitor.

### `D3DKMDT_MPR_MAXVALID`

Valid enumeration values were exceeded.

## Remarks

The setting of the **ValidatedAgainstMonitorCaps** member of the [D3DKMDT_DISPLAYMODE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmdt_displaymode_flags) structure indicates whether the monitor supports a display mode or not. If the monitor does not support a display mode, the operating system removes the display mode from the list of display modes that are available to the monitor.

When a display mode is supported, the reason type can be one of the following:

* D3DKMDT_MPR_DRIVER_RECOMMENDED_MONITOR_SOURCE_MODE
* D3DKMDT_MPR_DESCRIPTOR_MONITOR_SOURCE_MODE
* D3DKMDT_MPR_DESCRIPTOR_OVERRIDE_MONITOR_SOURCE_MODE
* D3DKMDT_MPR_DEFAULT_PROFILE_MONITOR_SOURCE_MODE
* D3DKMDT_MPR_MONITOR_FREQUENCY_RANGE_OVERRIDE

When a display mode is not supported, the reason type can be one of the following:

* D3DKMDT_MPR_DESCRIPTOR_MONITOR_FREQUENCY_RANGE
* D3DKMDT_MPR_DESCRIPTOR_OVERRIDE_MONITOR_FREQUENCY_RANGE
* D3DKMDT_MPR_ALLCAPS

## See also

[D3DKMDT_DISPLAYMODE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmdt_displaymode_flags)