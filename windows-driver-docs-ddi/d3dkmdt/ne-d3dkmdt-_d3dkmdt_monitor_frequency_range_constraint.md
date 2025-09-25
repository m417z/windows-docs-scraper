# _D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT enumeration

## Description

The D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT enumeration is used to indicate the type of constraint under which a monitor frequency range is supported.

## Constants

### `D3DKMDT_MFRC_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT has not yet been assigned a meaningful value.

### `D3DKMDT_MFRC_ACTIVESIZE`

Indicates that the constraint is an active region size.

### `D3DKMDT_MFRC_MAXPIXELRATE`

Indicates that the constraint is a pixel rate.

## Remarks

The **ConstraintType** member of a [D3DKMDT_MONITOR_FREQUENCY_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_frequency_range) structure is a value from the D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT enumeration.