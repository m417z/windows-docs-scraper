# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMSOURCERECT callback function

## Description

Sets the source rectangle for an input stream on the video processor.

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

If **TRUE**, the specified source rectangle must be applied to the input stream.

If **FALSE**, no source rectangle is applied to the input stream.

### `unnamedParam5`

*pSourceRect* [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the source rectangle.

**Note** If the *Enable* parameter is FALSE, this parameter is ignored.

## Remarks

The source rectangle is the portion of the input surface from which the video processor performs a bit-block transfer (bitblt) to the destination surface. The source rectangle is given in pixel coordinates, relative to the input surface.

If the **VideoProcessorSetStreamSourceRect** function is never called, or if the *Enable* parameter is FALSE, the video processor reads from the entire input surface.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)