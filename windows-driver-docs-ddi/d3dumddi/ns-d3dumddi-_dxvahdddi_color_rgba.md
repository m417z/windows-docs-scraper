# _DXVAHDDDI_COLOR_RGBA structure

## Description

The DXVAHDDDI_COLOR_RGBA structure describes color in RGB terms.

## Members

### `R` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the red component of the RGB color.

### `G` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the green component of the RGB color.

### `B` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the blue component of the RGB color.

### `A` [in]

A FLOAT value in the 0.0 to 1.0 range that is used to describe the alpha component (that is, the transparency level) of the RGB color.

## Remarks

The setting of DXVAHDDDI_COLOR_RGBA for full range RGB black with opaque alpha is (0.0, 0.0, 0.0, 1.0). The setting of DXVAHDDDI_COLOR_RGBA for limited range RGB black with half transparent alpha is (0.0625, 0.0625, 0.0625, 0.5), which is (0, 0, 0, 255) and (16, 16, 16, 128) respectively when 8-bit presentation is used.

R, G, and B values can be out of the [0.0, 1.0] range for wide gamut format (for example, for XR_BIAS, FP16, and FP32 formats).

A DXVAHDDDI_COLOR_YCbCrA structure is specified in the **RGB** member of the [DXVAHDDDI_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_color) union to specify the color in RGB terms.

## See also

[DXVAHDDDI_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_color)