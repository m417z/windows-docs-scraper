# _DXVAHDDDI_STREAM_STATE_ROTATION_DATA structure

## Description

Describes stream-state data that specifies the clockwise rotation of the display output surface.

## Members

### `Enable`

A Boolean value that specifies whether the driver should rotate the output surface. The default value is **FALSE**, which indicates that rotation is disabled.

### `Rotation`

The clockwise degrees of rotation as specified by a [DXVAHDDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_rotation) enumeration value.

## See also

[DXVAHDDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_rotation)