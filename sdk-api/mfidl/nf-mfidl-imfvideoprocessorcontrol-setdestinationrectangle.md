# IMFVideoProcessorControl::SetDestinationRectangle

## Description

Sets the destination rectangle. The destination rectangle is the portion of the output surface where the source rectangle is blitted.

## Parameters

### `pDstRect`

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the destination rectangle.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

See [Video Processor MFT](https://learn.microsoft.com/windows/desktop/medfound/video-processor-mft) for info regarding source and destination rectangles in the **Video Processor MFT**.

## See also

[IMFVideoProcessorControl](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideoprocessorcontrol)