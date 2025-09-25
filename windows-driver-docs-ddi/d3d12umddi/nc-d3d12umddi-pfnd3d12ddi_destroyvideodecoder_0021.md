# PFND3D12DDI_DESTROYVIDEODECODER_0021 callback function

## Description

Destroys the video decoder.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context).

### `hDrvVideoDecoder`

Holds the HVideoDecoder

## Remarks

The decoder may be used to record commands with multiple command lists, but commands cannot be recorded simultaneously. The application is responsible for synchronizing access to the decoder while recording commands.

Commands recorded against the decoder must also be executed in the order they were recorded. [Pfnd3d12ddiVideoDecodeFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_decode_frame_0032) operations may modify the contents of the decoder’s internal resources when they are executed on the GPU and subsequent Pfnd3d12ddiVideoDecodeFrame operations may depend upon those modifications.

On a single queue, the application is responsible for calling execute command lists in the order that Pfnd3d12ddiVideoDecodeFrame commands were recorded with the decoder object. When the application does so, the driver is then responsible for synchronizing Pfnd3d12ddiVideoDecodeFrame operations access to decoder resources.

When the application uses multiple queues with a single decoder object, the application is responsible for synchronizing and ordering the commands using fences.