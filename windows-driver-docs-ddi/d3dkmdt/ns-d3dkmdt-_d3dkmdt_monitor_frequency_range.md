# D3DKMDT_MONITOR_FREQUENCY_RANGE structure

## Description

The **D3DKMDT_MONITOR_FREQUENCY_RANGE** structure contains information about a range of frequencies supported by a monitor.

## Members

### `Origin`

A value from the [**D3DKMDT_MONITOR_CAPABILITIES_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_capabilities_origin) enumeration that indicates the source of the frequency range information.

### `RangeLimits`

A [**D3DKMDT_FREQUENCY_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_frequency_range) structure that contains the minimum and maximum refresh rates supported by the monitor.

### `ConstraintType`

A value from the [**D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_frequency_range_constraint) enumeration that specifies the type of constraint under which the frequency range is supported.

### `Constraint`

A union that contains either the active region size or the maximum pixel rate in the following members.

### `Constraint.ActiveSize`

If **ConstraintType** is equal to D3DKMDT_MFRC_ACTIVESIZE, then this member specifies the maximum active region size for which the frequency range is supported.

### `Constraint.MaxPixelRate`

If **ConstraintType** is equal to D3DKMDT_MFRC_MAXPIXELRATE, then this member specifies the maximum pixel rate for which the frequency range is supported.