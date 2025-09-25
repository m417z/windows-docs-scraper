# _DXVA_DeinterlaceCaps structure

## Description

The DXVA_DeinterlaceCaps structure describes the driver capabilities for a deinterlace mode.

## Members

### `Size`

Indicates the size of this structure.

### `NumPreviousOutputFrames`

Indicates the number of required frames previously output by the deinterlace algorithm. This member is used by recursive deinterlace algorithms.

### `InputPool`

Indicates the memory pool from which the interlaced source surfaces should be allocated. For more information, see the D3DPOOL enumeration type in the Microsoft Window SDK documentation.

### `NumForwardRefSamples`

Indicates the required number of forward reference samples for the defined deinterlace mode. These samples will be in future fields. This value is zero for bob and line blending, and can be several values for adaptive deinterlacing and frame-rate conversion.

### `NumBackwardRefSamples`

Indicates the required backward reference samples for the defined deinterlace mode. The samples are in past fields. This value is zero for bob, 1 for line blending, and can be several values for adaptive deinterlacing and frame-rate conversion.

### `d3dOutputFormat`

Indicates the Direct3D surface format of the output frames. Usually a deinterlace algorithm outputs frames in a surface format that matches the input sample format. This member ensures that the VMR or other video renderer will be able to supply the correct output frame surfaces to the deinterlace hardware.

Note that if the **DXVA_Deinterlace_YUV2RGB** enumerator is returned in the [DXVA_VideoProcessCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videoprocesscaps) enumeration, the VMR will assume that valid output formats are specified by this member, in addition to a D3DFMT_X8R8G8B8 format.

### `VideoProcessingCaps`

Specifies a [DXVA_VideoProcessCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videoprocesscaps) enumeration indicating the operation that can be performed concurrently with the requested deinterlace.

### `DeinterlaceTechnology`

Specifies a [DXVA_DeinterlaceTech](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_deinterlacetech) enumeration indicating the deinterlacing technology used by this deinterlacing device.

## Remarks

The driver receives the DXVA_DeinterlaceCaps structure with the **Size** member assigned, assigns values to the remaining members, and returns DXVA_DeinterlaceCaps to the renderer.

## See also

[DXVA_DeinterlaceTech](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_deinterlacetech)

[DXVA_VideoProcessCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videoprocesscaps)