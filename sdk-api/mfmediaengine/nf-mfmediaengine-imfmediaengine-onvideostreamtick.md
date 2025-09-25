# IMFMediaEngine::OnVideoStreamTick

## Description

Queries the Media Engine to find out whether a new video frame is ready.

## Parameters

### `pPts` [out]

If a new frame is ready, receives the presentation time of the frame.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The method succeeded, but the Media Engine does not have a new frame. |
| **S_OK** | A new video frame is ready for display. |

## Remarks

In frame-server mode, the application should call this method whenever a vertical blank occurs in the display device. If the method returns **S_OK**, call [IMFMediaEngine::TransferVideoFrame](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-transfervideoframe) to blit the frame to the render target. If the method returns **S_FALSE**, wait for the next vertical blank and call the method again.

Do not call this method in rendering mode or audio-only mode.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)