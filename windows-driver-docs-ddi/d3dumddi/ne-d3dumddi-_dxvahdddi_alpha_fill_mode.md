# _DXVAHDDDI_ALPHA_FILL_MODE enumeration

## Description

The DXVAHDDDI_ALPHA_FILL_MODE enumeration contains values that identify the type of alpha fill mode to set.

## Constants

### `DXVAHDDDI_ALPHA_FILL_MODE_OPAQUE`

A value that specifies to fill the output with opaque alpha channel data.

### `DXVAHDDDI_ALPHA_FILL_MODE_BACKGROUND`

A value that specifies to fill the output with the alpha channel data of the background. For more information about background color, see [DXVAHDDDI_BLT_STATE_BACKGROUND_COLOR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_background_color_data).

### `DXVAHDDDI_ALPHA_FILL_MODE_DESTINATION`

A value that specifies to keep the alpha channel data unchanged on the target output.

### `DXVAHDDDI_ALPHA_FILL_MODE_SOURCE_STREAM`

A value that specifies to fill the output with the alpha channel data of the destination rectangle in which the source rectangle of the specified input stream is scaled. For more information about the conditions for this value, see the Remarks section of [DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_alpha_fill_data).

## See also

[DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_alpha_fill_data)

[DXVAHDDDI_BLT_STATE_BACKGROUND_COLOR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_background_color_data)