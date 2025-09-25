# PFND3D11_1DDI_VIDEOPROCESSORSETOUTPUTTARGETRECT callback function

## Description

Sets the target rectangle for the video processor.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*Enable* [in]

If **TRUE**, the target rectangle specified by the *pOutputRect* parameter should be used by the video processor.

### `unnamedParam4`

*pOutputRect* [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the target rectangle.

**Note** If the *Enable* parameter is FALSE, this parameter is ignored.

## Remarks

The target rectangle is the area within the destination surface where the output will be drawn. The target rectangle is given in pixel coordinates, relative to the destination surface.

If this function is never called, or if the *Enable* parameter is FALSE, the video processor writes to the entire destination surface.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)