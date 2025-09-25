# _DXVA_DeinterlaceBltEx32 structure

## Description

The DXVA_DeinterlaceBltEx structure describes parameters for deinterlace or frame-rate conversion, for combining the deinterlaced or frame-rate converted video with any supplied video substreams, and for writing the combined output to a destination surface. It is used for forwarding 32-bit [DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex) calls on 64-bit drivers.

## Members

### `Size`

Specifies the size of the structure, in bytes.

### `BackgroundColor`

Specifies a [DXVA_AYUVsample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_ayuvsample2) structure that identifies background color and opacity level. For Windows Server 2003 with SP1 and Windows XP with SP2, the opacity level is not used and should be ignored by the driver.

### `rcTarget`

Specifies a pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the location within the destination surface to which the output image is written. Note that the output image is restricted to the pixels within the **rcTarget** rectangle--that is, every pixel within this rectangle must be written to; pixels outside this rectangle must not be modified.

### `rtTarget`

Identifies the location of the output frame within the sequence of input frames. If only deinterlacing is performed, the target time should coincide with either the starting display time of a sample, as defined in the [DXVA_VideoSample32](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample32) structure, or the midpoint between the starting display time and the ending display time. For more information, see Remarks.

If a frame-rate conversion is requested, the **rtTarget** time can be different from any of the **rtStart** times of the samples.

### `NumSourceSurfaces`

Specifies the number of valid surfaces passed in the **Source** array.

### `Alpha`

Specifies the planar-transparency value of the output image as it is written to the destination surface. For Windows Server 2003 with SP1 and Windows XP with SP2, this value is always 1.0F, which indicates that the overall image is opaque and that no alpha blending on the overall image is required.

### `Source`

Specifies an array of DXVA_VideoSample32 structures that describe the input samples that are required for the deinterlacing, frame-rate conversion, and substream-compositing operations. For information about how input samples are arranged in this array, see [Input Buffer Order](https://learn.microsoft.com/windows-hardware/drivers/display/input-buffer-order).

### `DestinationFormat`

Specifies format information for the destination surface. For Windows Server 2003 with SP1 and Windows XP with SP2, this member is set to 0.

### `DestinationFlags`

Specifies a collection of flags that indicate changes in the current destination surface from the previous destination surface. This member is a bitwise-OR of one or more of the flags in the [DXVA_DestinationFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_destinationflags) enumeration type.

## See also

[DXVA_DeinterlaceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacecaps)

[DXVA_DestinationFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_destinationflags)

[DXVA_VideoSample32](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample32)

[DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex)