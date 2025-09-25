# _DXVAHDDDI_BLT_STATE_BACKGROUND_COLOR_DATA structure

## Description

The DXVAHDDDI_BLT_STATE_BACKGROUND_COLOR_DATA structure describes data that specifies the background color to fill in the target rectangle of the output.

## Members

### `YCbCr` [in]

A Boolean value that specifies whether the driver should determine whether the **BackgroundColor** member specifies a YCbCr or RGB color space. The default value is **FALSE**, which indicates a RGB color space. **TRUE** specifies a YCbCr color space.

### `BackgroundColor` [in]

A [DXVAHDDDI_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_color) union that specifies the background color as either a YCbCr or RGB color space. The default value is full range RGB black with opaque alpha, that is (R,G,B,A) = (0.0,0.0,0.0,1.0).

## Remarks

The color space of the background color is determined by the color space of the output. For more information about output color space, see [DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_output_color_space_data).

The alpha value of the background color is used when the DXVAHDDDI_ALPHA_FILL_MODE_BACKGROUND value is specified in the alpha fill mode (that is, the **Mode** member of the [DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_alpha_fill_data) structure) when the DXVAHDDDI_BLT_STATE_ALPHA_FILL value is specified in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate) structure in a call to the [SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate) function.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate)

[DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_alpha_fill_data)

[DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_output_color_space_data)

[DXVAHDDDI_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_color)

[SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate)