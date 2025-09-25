# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMROTATION callback function

## Description

Enables or disables rotation on an input stream of the video processor.

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

*Rotation* [in]

The clockwise degrees of rotation as specified by a [D3D11_1DDI_VIDEO_PROCESSOR_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_rotation) enumeration value.

### `unnamedParam5`

*Enable* [in]

If **TRUE**, rotation is enabled on the input stream. Otherwise, rotation is disabled on the input stream.

## Remarks

The stream source rectangle will be specified in the pre-rotation coordinates (typically landscape) and the stream destination rectangle will be specified in the post-rotation coordinates (typically portrait).

The application must update the stream destination rectangle correctly when using a rotation value other than 0 or 180 degrees.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_rotation)