# _D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD structure

## Description

The D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD structure describes a Microsoft DirectX Video Acceleration (VA) video processing high definition operation to perform.

## Members

### `hVideoProcessor` [in]

A handle to the DirectX VA video processing device. The user-mode display driver returns this handle in a call to its [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor) function.

### `OutputSurface` [in]

A [DXVAHDDDI_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_surface) structure that describes the output surface to which the video processor composes.

### `OutputFrame` [in]

A zero-based frame number of the composed output frames.

### `StreamCount` [in]

The number of streams to process. This number must be less than the number that the driver set in the **MaxStreamStates** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure.

### `pStreams` [in]

An array of [DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data) structures that describe the input streams to process.

## Remarks

The output surface that the **OutputSurface** member specifies, which must be one of the following surface types:

* A video surface that is created with the DXVAHD_SURFACE_TYPE_VIDEO_OUTPUT type.
* A render target surface or a surface that is created with D3DUSAGE_RENDERTARGET usage.
* A swap chain.
* A swap chain with overlay swap effect.

If the frame that the **OutputFrame** member specifies remains unchanged at the next process time, the driver determines that the frame is unchanged (for example, paused) in the entire video processing and composition. Therefore, the driver can use cached data to optimize the frame.

The driver also uses the frame that the **OutputFrame** member specifies for tagging the command, which the driver submits to the graphics processing unit (GPU).

Input streams are indexed from zero to less than the number that the driver sets in the **MaxStreamStates** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure. Each stream has its own stream states associated with the stream index number. The driver processes each stream from zero index and blends on the destination surface one after another. For example, if a video stream is at index zero and a graphics stream is at index one, the driver blends the video stream on the background color and then blends the graphics stream over them.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor)

[DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data)

[DXVAHDDDI_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_surface)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)