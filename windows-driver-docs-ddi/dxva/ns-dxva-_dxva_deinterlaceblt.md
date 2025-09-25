# _DXVA_DeinterlaceBlt structure

## Description

The DXVA_DeinterlaceBlt structure is sent by the VMR to the accelerator to specify the deinterlace or frame-rate conversion parameters for bit-block transfers.

## Members

### `Size`

Specifies the size of this structure in bytes.

### `Reserved`

### `rtTarget`

Identifies the location of the output frame within the sequence of input frames. If only deinterlacing is performed, the target time should coincide with either the starting display time of a reference sample, as defined in the [DXVA_VideoSample](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample) structure, or the midpoint between the starting display time and the ending display time. For more information, see Remarks.

If a frame rate conversion is requested, the **rtTarget** time can be different from any of the **rtStart** times of the reference samples.

### `DstRect`

Specifies a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the upper left and lower right points of a rectangle on the destination surface. These points define the area in which the bit-block transfer should occur and its position on the destination surface.

### `SrcRect`

Specifies a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the upper left and lower right points of a rectangle on the source surface. These points define the area of the source data for the bit-block transfer and its position on the source surface.

### `NumSourceSurfaces`

Specifies the number of valid surfaces passed in the **Source** array.

### `Alpha`

Specifies the transparency of the output image as it is written to the destination surface. A value of 0.0F indicates transparent. A value of 1.0F indicates opaque.

### `Source`

An array of [DXVA_VideoSample](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample) structures that specify the reference input samples needed for this deinterlacing or frame-rate conversion operation.

## Remarks

When creating a single frame from one field in a sample, as defined in the [DXVA_VideoSample](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample) structure, **rtTarget** should be the starting display time for that field. If you have two fields in one sample and want to deinterlace both, [DeinterlaceBlt](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlaceblt) will be called twice. The first time *DeinterlaceBlt* is called, **rtTarget** will be the starting display time. The second time *DeinterlaceBlt* is called, **rtTarget** will be the midpoint between the starting display time and the ending display time. In other words, for the first call, **rtTarget** = **rtStart**. For the second call, **rtTarget** = (**rtStart** + **rtEnd**) / 2.

## See also

[DXVA_DeinterlaceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacecaps)

[DXVA_VideoSample](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videosample)

[DeinterlaceBlt](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlaceblt)