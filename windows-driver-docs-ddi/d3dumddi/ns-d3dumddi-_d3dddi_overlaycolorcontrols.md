# _D3DDDI_OVERLAYCOLORCONTROLS structure

## Description

The D3DDDI_OVERLAYCOLORCONTROLS structure describes color-control settings for an overlay.

## Members

### `BrightnessSetting` [in]

An INT value that specifies the brightness of the output image as it is written to the overlay. This member is set if the **Brightness** bit-field flag is set in the **Flags** member.

### `ContrastSetting` [in]

An INT value that specifies the contrast of the output image as it is written to the overlay. This member is set if the **Contrast** bit-field flag is set in the **Flags** member.

### `HueSetting` [in]

An INT value that specifies the hue of the output image as it is written to the overlay. This member is set if the **Hue** bit-field flag is set in the **Flags** member.

### `SaturationSetting` [in]

An INT value that specifies the saturation of the output image as it is written to the overlay. This member is set if the **Saturation** bit-field flag is set in the **Flags** member.

### `SharpnessSetting` [in]

An INT value that specifies the sharpness of the output image as it is written to the overlay. This member is set if the **Sharpness** bit-field flag is set in the **Flags** member.

### `GammaSetting` [in]

An INT value that specifies the gamma setting of the output image as it is written to the overlay. This member is set if the **Gamma** bit-field flag is set in the **Flags** member.

### `ColorEnableSetting` [in]

An INT value that specifies the color-enable setting of the output image as it is written to the overlay. This member is set if the **ColorEnable** bit-field flag is set in the **Flags** member.

### `Flags` [in]

A [D3DDDI_OVERLAYCOLORCONTROLSFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlaycolorcontrolsflags) structure that identifies color-control settings that the overlay hardware supports.

## See also

[D3DDDIARG_GETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getoverlaycolorcontrols)

[D3DDDIARG_SETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setoverlaycolorcontrols)

[D3DDDI_OVERLAYCOLORCONTROLSFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlaycolorcontrolsflags)