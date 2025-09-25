# IMFMediaEngineEx::UpdateVideoStream

## Description

Updates the source rectangle, destination rectangle, and border color for the video.

## Parameters

### `pSrc` [in]

A pointer to an [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure that specifies the source rectangle. The source rectangle defines the area of the video frame that is displayed. If this parameter is **NULL**, the entire video frame is displayed.

### `pDst` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the destination rectangle. The destination rectangle defines the area of the window or DirectComposition visual where the video is drawn.

### `pBorderClr` [in]

A pointer to an [MFARGB](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfargb) structure that specifies the border color.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In rendering mode, call this method to reposition the video, update the border color, or repaint the video frame. If all of the parameters are **NULL**, the method repaints the most recent video frame.

In frame-server mode, this method has no effect.

See [Video Processor MFT](https://learn.microsoft.com/windows/desktop/medfound/video-processor-mft) for info regarding source and destination rectangles in the **Video Processor MFT**.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)