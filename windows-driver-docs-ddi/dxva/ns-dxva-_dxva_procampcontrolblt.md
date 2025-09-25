# _DXVA_ProcAmpControlBlt structure

## Description

The DXVA_ProcAmpControlBlt structure contains the ProcAmp adjustment data that is output to the destination surface.

## Members

### `Size`

Specifies the size of this structure in bytes.

### `DstRect`

Specifies the destination rectangle as a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure. The destination rectangle is required for subrectangle stretching. Support for stretching is optional and is reported by the [DXVA_ProcAmpControlCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_procampcontrolcaps) structure. Support for subrectangles is optional.

### `SrcRect`

Specifies the source rectangle as a RECT structure. The source rectangle is required for subrectangle stretching.sub Support for stretching is optional and is reported by the DXVA_ProcAmpControlCaps structure. Support for subrectangles is also optional.

### `Alpha`

Specifies the transparency of the output image as it is written to the destination surface. A value of 0.0F indicates transparent. A value of 1.0F indicates opaque.

### `Brightness`

Specifies the brightness of the output image as it is written to the destination surface.

### `Contrast`

Specifies the contrast of the output image as it is written to the destination surface.

### `Hue`

Specifies the hue of the output image as it is written to the destination surface.

### `Saturation`

Specifies the saturation of the output image as it is written to the destination surface.

## See also

[DXVA_ProcAmpControlCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_procampcontrolcaps)

[DXVA_ProcAmpControlQueryRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_procampcontrolqueryrange)