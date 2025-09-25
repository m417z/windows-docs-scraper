# IMFVideoProcessorControl::SetRotation

## Description

Specifies whether to rotate the video to the correct orientation.

## Parameters

### `eRotation`

A [MF_VIDEO_PROCESSOR_ROTATION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_video_processor_rotation) value that specifies whether to rotate the image.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The original orientation of the video is specified by the [MF_MT_VIDEO_ROTATION](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-rotation) attribute of the input media type.

 If *eRotation* is **ROTATION_NONE**, the video processor does not correct the orientation of the output video. If the original video is rotated, and *eRotation* is **ROTATION_NORMAL**, the video processor corrects the orientation, so that the output video is not rotated. The video processor letterboxes the output as needed.

## See also

[IMFVideoProcessorControl](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideoprocessorcontrol)