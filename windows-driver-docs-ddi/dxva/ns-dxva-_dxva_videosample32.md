# _DXVA_VideoSample32 structure

## Description

The DXVA_VideoSample32 structure is used for forwarding 32-bit [DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex) calls on 64-bit drivers.

## Members

### `rtStart`

Specifies the start time of the sample.

### `rtEnd`

Specifies the end time of the sample.

### `SampleFormat`

Specifies the format of the sample as defined by values of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) enumeration type.

### `SampleFlags`

Specifies a collection of flags that indicate changes in the current sample frame from the previous sample frame. This member is a bitwise-OR of one or more of the flags in the [DXVA_SampleFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleflags) enumeration type.

### `lpDDSSrcSurface`

Pointer to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure that represents the sample.

### `rcSrc`

Specifies a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the upper-left and lower-right points of a rectangle on the source surface. These points define the area of the source data for the bit-block transfer and its position on the source surface.

### `rcDst`

Specifies a RECT structure that describes the upper-left and lower-right points of a rectangle on the destination surface. These points define the area in which the bit-block transfer should occur and its position on the destination surface.

### `Palette`

Specifies an array of [DXVA_AYUVsample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_ayuvsample2) structures that represent a complete 16-color palette for palletized video substream pixel formats. The driver uses this palette to composite the substream sample. For nonpalletized pixel formats, the palette is zero and can be ignored.

## Remarks

The compiler adds 4 bytes of padding to align the structure to 8 bytes.

## See also

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local)

[DXVA_AYUVsample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_ayuvsample2)

[DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex)

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)

[DXVA_SampleFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleflags)

[DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)