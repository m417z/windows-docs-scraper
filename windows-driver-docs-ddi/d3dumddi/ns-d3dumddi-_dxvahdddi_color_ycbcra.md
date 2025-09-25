# _DXVAHDDDI_COLOR_YCbCrA structure

## Description

The DXVAHDDDI_COLOR_YCbCrA structure describes color in YCbCr terms.

## Members

### `Y` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the luma component of the YCbCr color.

### `Cb` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the blue chroma component of the YCbCr color.

### `Cr` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the red chroma component of the YCbCr color.

### `A` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the alpha component (that is, the transparency level) of the YCbCr color.

## Remarks

The setting of DXVAHDDDI_COLOR_YCbCrA for YCbCr black with opaque alpha is (0.0625, 0.5, 0.5, 1.0), which is (16, 128, 128, 255) when 8-bit presentation is used.

A DXVAHDDDI_COLOR_YCbCrA structure is specified in the **YCbCr** member of the [DXVAHDDDI_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_color) union to specify the color in YCbCr terms.

## See also

[DXVAHDDDI_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_color)