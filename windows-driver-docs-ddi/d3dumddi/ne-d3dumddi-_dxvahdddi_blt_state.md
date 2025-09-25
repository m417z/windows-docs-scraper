# _DXVAHDDDI_BLT_STATE enumeration

## Description

The DXVAHDDDI_BLT_STATE enumeration contains values that identify the bit-block transfer (bitblt) state data for a video processor.

## Constants

### `DXVAHDDDI_BLT_STATE_TARGET_RECT`

The bitblt state data specifies the target rectangle of the output in a [DXVAHDDDI_BLT_STATE_TARGET_RECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_target_rect_data) structure.

### `DXVAHDDDI_BLT_STATE_BACKGROUND_COLOR`

The bitblt state data specifies the background color to fill in the target rectangle of the output in a [DXVAHDDDI_BLT_STATE_BACKGROUND_COLOR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_background_color_data) structure.

### `DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE`

The bitblt state data specifies the color space of the output in a [DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_output_color_space_data) structure.

### `DXVAHDDDI_BLT_STATE_ALPHA_FILL`

The bitblt state data specifies the alpha-fill mode of the output in a [DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_alpha_fill_data) structure.

### `DXVAHDDDI_BLT_STATE_CONSTRICTION`

The bitblt state data specifies the down sampling of the output in a [DXVAHDDDI_BLT_STATE_CONSTRICTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_constriction_data) structure.

### `DXVAHDDDI_BLT_STATE_PRIVATE`

The bitblt state data specifies the private parameters in a [DXVAHDDDI_BLT_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_private_data) structure.

## Remarks

A DXVAHDDDI_BLT_STATE-typed value, which is specified in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate) structure in a call to the [SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate) function, sets the state of a bitblt for a video processor. Bitblt data that corresponds to the supplied DXVAHDDDI_BLT_STATE-typed value is pointed to by the **pData** member of D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate)

[DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_alpha_fill_data)

[DXVAHDDDI_BLT_STATE_BACKGROUND_COLOR_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_background_color_data)

[DXVAHDDDI_BLT_STATE_CONSTRICTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_constriction_data)

[DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_output_color_space_data)

[DXVAHDDDI_BLT_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_private_data)

[DXVAHDDDI_BLT_STATE_TARGET_RECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_target_rect_data)

[SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate)