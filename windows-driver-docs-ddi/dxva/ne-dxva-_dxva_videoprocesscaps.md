# _DXVA_VideoProcessCaps enumeration

## Description

The DXVA_VideoProcessCaps enumeration identifies operations that can be performed concurrently with the requested deinterlace.

## Constants

### `DXVA_VideoProcess_None`

Indicates that the deinterlace hardware can only perform basic deinterlace operations. That is, deinterlace operations that are not combined with other operations, like-color conversion, alpha blend, stretch, subsection, or substream.

### `DXVA_VideoProcess_YUV2RGB`

Indicates that the deinterlace hardware can convert video from the YUV color space to the RGB color space. The RGB format will have at least 8 bits of precision for each color component. If possible, a buffer copy within the VMR can be avoided. All drivers should be able to support this operation for the bob deinterlace mode.

Not used with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

### `DXVA_VideoProcess_StretchX`

Indicates that aspect ratio correction can be performed simultaneously as the video is being deinterlaced if the deinterlacer is able to stretch or shrink horizontally. The enumerator should be supported for the bob deinterlace mode.

Must use with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

### `DXVA_VideoProcess_StretchY`

Indicates that aspect ratio adjustment is combined with a general picture resizing operation to scale the video image.

Must use with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

### `DXVA_VideoProcess_AlphaBlend`

Indicates that the VMR will not perform a buffer copy when an alpha value is changed. It is rare that applications alter the constant alpha value associated with the video stream, so this is a low priority feature. The enumerator should be supported for the bob deinterlace mode.

Not used with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

### `DXVA_VideoProcess_SubRects`

Indicates that the deinterlace hardware can deinterlace just a subrectangle region of the video image to the specified destination position. This is useful if the video image must be cropped before being processed further as the size of the output frame is reduced.

### `DXVA_VideoProcess_SubStreams`

Windows Server 2003 SP1 and later and Windows XP SP2 and later versions only.

Indicates that the deinterlace hardware can combine video substreams with the video stream.

Must use with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

### `DXVA_VideoProcess_SubStreamsExtended`

Windows Server 2003 SP1 and later and Windows XP SP2 and later versions only.

Indicates that necessary color adjustments can be made to the source video streams and substreams. These adjustments are indicated in the extended color data, as the video is deinterlaced, composited with the substreams, and written to the destination surface.

Must use with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

### `DXVA_VideoProcess_YUV2RGBExtended`

Windows Server 2003 SP1 and later and Windows XP SP2 and later versions only.

Indicates a color-space-conversion operation can be performed as the deinterlaced and composited pixels are written to the destination surface using the extended color information that is specified for the source and destination surfaces.

Must use with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

### `DXVA_VideoProcess_AlphaBlendExtended`

Windows Server 2003 SP1 and later and Windows XP SP2 and later versions only.

Indicates that an alpha-blend operation can be performed with the destination surface when the deinterlaced and composited pixels are written to the destination surface. The driver must handle background color based on the alpha value of the **Alpha** member of the [DXVA_DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacebltex) structure. When the alpha value is 1.0f, the background color is drawn opaque (without transparency). When the alpha value is 0.0f, the background should not be drawn (transparent).

Must use with the [DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex) function.

## Remarks

Occasionally, the aspect ratio adjustment performed by **DXVA_VideoProcess_AlphaBlend** is combined with a general picture resizing operation to scale the video image within an application-defined composition space, which is rare and not an essential feature. It is best if the scaling needed for resizing the video to fit into the application window can be done simultaneously to the scaling needed for deinterlacing, which avoids cumulative artifacts.

Color space conversion performed by **DXVA_VideoProcess_YUV2RGB** is particularly useful within the VMR if it is combined with any (and ideally, all) of the following enumerators: **DXVA_VideoProcess_StretchX**, **DXVA_VideoProcess_StretchY**, and **DXVA_VideoProcess_AlphaBlend**. There is no requirement to convert from the RGB color space to the YUV color space.

## See also

[DXVA_DeinterlaceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacecaps)

[DeinterlaceBltEx](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacebobdeviceclass-deinterlacebltex)