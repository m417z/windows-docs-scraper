# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMDESTRECT callback function

## Description

Sets the destination rectangle for an input stream on the video processor.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*StreamIndex* [in]

The zero-based index of the input stream.

### `unnamedParam4`

*Enable* [in]

If **TRUE**, the destination rectangle specified by the *pDestRect* parameter should be used by the video processor.

### `unnamedParam5`

*pDestRect* [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the destination rectangle.

**Note** If the *Enable* parameter is **FALSE**, this parameter is ignored.

## Remarks

The destination rectangle is the portion of the output surface that receives the bit-block transfer (bitblt) for the specified input stream. The destination rectangle is given in pixel coordinates, relative to the output surface.

The default destination rectangle is an empty rectangle (0, 0, 0, 0). If the *VideoProcessorSetStreamDestRect* function is never called, or if the *Enable* parameter is **FALSE**, no data is written from the specified input stream.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)