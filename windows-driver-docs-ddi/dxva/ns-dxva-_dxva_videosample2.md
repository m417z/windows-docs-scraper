# _DXVA_VideoSample2 structure

## Description

The DXVA_VideoSample2 structure is sent by the renderer to the driver to specify the format of a video sample.

## Members

### `Size`

**Only compiles for a 64-bit version of the operating system.**

Indicates the size of this structure.

### `Reserved`

**Only compiles for a 64-bit version of the operating system.**

Reserved.

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

For video substream samples, the **rtStart** and **rtEnd** members are set to 0.

The **SampleFormat** member indicates whether the sample is a reference for a deinterlace operation or a video substream sample that must be combined with the deinterlaced video frame. The DXVA_SampleSubStream value (new for Windows Server 2003 with SP1 and later and Windows XP with SP2 and later) of the [DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat) enumeration type specifies the format for a video substream sample.

The **SampleFlags** member contains a collection of flags that indicate changes in the current sample frame from the previous sample frame. You can use these flags to optimize your driver code. In other words, your code is not required to perform operations on the current sample frame if no changes have occurred from the previous sample frame.

For information about how input samples are arranged in the array in the **Source** member of the [DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex) structure, see [Input Buffer Order](https://learn.microsoft.com/windows-hardware/drivers/display/input-buffer-order).

## See also

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local)

[DXVA_AYUVsample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_ayuvsample2)

[DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex)

[DXVA_DeinterlaceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacecaps)

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)

[DXVA_SampleFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleflags)

[DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)