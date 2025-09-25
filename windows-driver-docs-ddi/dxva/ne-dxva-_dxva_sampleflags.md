# _DXVA_SampleFlags enumeration

## Description

The DXVA_SampleFlags enumeration type contains a collection of flags that identify changes in the current sample frame from the previous sample frame.

## Constants

### `DXVA_SampleFlagsMask`

Specifies the sample-flag mask, which consists of the first 4 bits of a DWORD.

### `DXVA_SampleFlag_Palette_Changed`

Indicates that the palette of the sample frame changed.

### `DXVA_SampleFlag_SrcRect_Changed`

Indicates that the source rectangle of the sample frame changed.

### `DXVA_SampleFlag_DstRect_Changed`

Indicates that the destination rectangle of the sample frame changed.

### `DXVA_SampleFlag_ColorData_Changed`

Indicates that the color data of the sample frame changed.

## See also

[DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex)

[DXVA_DeinterlaceBobDeviceClass::DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex)

[DXVA_VideoSample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample2)