# _D3DDDIARG_VIDEOPROCESSBLT structure

## Description

The D3DDDIARG_VIDEOPROCESSBLT structure describes a Microsoft DirectX Video Acceleration (VA) video processing operation to perform.

## Members

### `TargetFrame` [in]

A REFERENCE_TIME value that identifies the location of the output frame within the sequence of input frames. If only deinterlacing is performed, the target time should coincide with either the starting display time of a sample, as defined by the **Start** member in the [DXVADDI_VIDEOSAMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videosample) structure, or the midpoint between the starting display time and the ending display time.

If a frame rate conversion is requested, the time in **TargetFrame** can be different from any of the times in the **Start** members of the samples.

### `hVideoProcess` [in]

A handle to the DirectX VA video processing device. The user-mode display driver returns this handle in a call to its [CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice) function.

### `TargetRect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the location within the destination surface to which the output image is written. Note that the output image is restricted to the pixels within the rectangle that is pointed to by **TargetRect**. That is, every pixel within this rectangle must be written to; pixels outside this rectangle must not be modified.

### `ConstrictionSize` [in]

A [SIZE](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/microsoft-windows-smbserver-size) structure that specifies, for protected content, the size to reduce the output image to. **ConstrictionSize** should be from (1, 1) to (width, height) of the target rectangle that is specified in the **TargetRect** member. **ConstrictionSize** should be (0, 0) to represent no constriction.

For example, consider video that natively has 1920 x 1080 pixels and that is displayed full screen on a 1920 x 1080-resolution monitor for which output protection is unsupported. If the video content specifies a rule that only 854 x 480 pixels of original information can be displayed, the driver must reduce the original image from 1920 x 1080 to 854 x 480 and then stretch the image again to 1920 x 1080. In this example, the SIZE structure in the **ConstrictionSize** member would specify a size of 854 x 480 pixels.

### `StreamingFlags` [in]

A UINT value that identifies streaming flags. Currently, no streaming flags are defined.

### `BackgroundColor` [in]

A [DXVADDI_AYUVSAMPLE16](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_ayuvsample16) structure that identifies background color.

### `DestFormat` [in]

A [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure that identifies extended format information for the destination surface.

### `DestFlags` [in]

A [DXVADDI_VIDEOPROCESSBLTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessbltflags) structure that identifies changes in the current destination surface from the previous destination surface.

### `ProcAmpValues` [in]

A [DXVADDI_PROCAMPVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_procampvalues) structure that specifies ProcAmp adjustment data that is output to the destination surface.

### `Alpha` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the planar-transparency value of the output image as it is written to the destination surface. When the alpha value is 1.0, the background color is drawn opaque (without transparency and alpha blending). When the alpha value is 0.0, the background should not be drawn (transparent).

### `NoiseFilterLuma` [in]

A [DXVADDI_FILTERVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_filtervalues) structure that specifies the luma noise filter.

### `NoiseFilterChroma` [in]

A [DXVADDI_FILTERVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_filtervalues) structure that specifies the chroma noise filter.

### `DetailFilterLuma` [in]

A [DXVADDI_FILTERVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_filtervalues) structure that specifies the luma detail filter.

### `DetailFilterChroma` [in]

A [DXVADDI_FILTERVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_filtervalues) structure that specifies the chroma detail filter.

### `pSrcSurfaces` [in]

An array of [DXVADDI_VIDEOSAMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videosample) structures that describe the input samples that are required for the deinterlacing, frame-rate conversion, and substream compositing operations. For more information about how input samples are arranged in this array, see [Input Buffer Order](https://learn.microsoft.com/windows-hardware/drivers/display/input-buffer-order).

### `NumSrcSurfaces` [in]

The number of input samples in the array at **pSrcSurfaces**.

## See also

[CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice)

[DXVADDI_AYUVSAMPLE8](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_ayuvsample8)

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)

[DXVADDI_PROCAMPVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_procampvalues)

[DXVADDI_VIDEOPROCESSBLTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videoprocessbltflags)

[DXVADDI_VIDEOSAMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videosample)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)

[VideoProcessBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessblt)