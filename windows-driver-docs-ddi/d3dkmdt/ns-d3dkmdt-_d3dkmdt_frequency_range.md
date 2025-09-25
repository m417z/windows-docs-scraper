# _D3DKMDT_FREQUENCY_RANGE structure

## Description

The D3DKMDT_FREQUENCY_RANGE structure contains the minimum and maximum refresh rates supported by a monitor.

## Members

### `MinVSyncFreq`

The minimum vertical refresh rate, in Hz, supported by the monitor.

### `MaxVSyncFreq`

The maximum vertical refresh rate, in Hz, supported by the monitor.

### `MinHSyncFreq`

The minimum horizontal refresh rate, in Hz, supported by the monitor.

### `MaxHSyncFreq`

The maximum horizontal refresh rate, in Hz, supported by the monitor.

## Remarks

The **RangeLimits** member of the [D3DKMDT_MONITOR_FREQUENCY_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_frequency_range) structure is a D3DKMDT_FREQUENCY_RANGE structure.

## See also

[Monitor Frequency Range Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)