# _DXVADDI_PROCAMPVALUES structure

## Description

The DXVADDI_PROCAMPVALUES structure describes the ProcAmp control adjustment values.

## Members

### `Brightness` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the brightness of the output image, as it is written to the destination surface.

### `Contrast` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the contrast of the output image, as it is written to the destination surface.

### `Hue` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the hue of the output image, as it is written to the destination surface.

### `Saturation` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the saturation of the output image, as it is written to the destination surface.

## See also

[D3DDDIARG_VIDEOPROCESSBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_videoprocessblt)