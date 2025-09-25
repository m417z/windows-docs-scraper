# _DXVAHDDDI_DEVICE_USAGE enumeration

## Description

The DXVAHDDDI_DEVICE_USAGE enumeration contains values that identify how the decode device plays video.

## Constants

### `DXVAHDDDI_DEVICE_USAGE_PLAYBACK_NORMAL`

A value that specifies that the device plays video at normal speed.

### `DXVAHDDDI_DEVICE_USAGE_OPTIMAL_SPEED`

A value that specifies that the device plays video at optimal speed.

### `DXVAHDDDI_DEVICE_USAGE_OPTIMAL_QUALITY`

A value that specifies that the device plays video at optimal quality.

## Remarks

A DXVAHDDDI_DEVICE_USAGE-typed value is specified in the **Usage** member of a [DXVAHDDDI_DEVICE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_device_desc) structure to help describe a decode device.

## See also

[DXVAHDDDI_DEVICE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_device_desc)