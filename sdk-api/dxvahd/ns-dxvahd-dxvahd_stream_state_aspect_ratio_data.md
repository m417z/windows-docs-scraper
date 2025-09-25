# DXVAHD_STREAM_STATE_ASPECT_RATIO_DATA structure

## Description

Specifies the pixel aspect ratio (PAR) for the source and destination rectangles.

## Members

### `Enable`

**If TRUE**, the **SourceAspectRatio** and **DestinationAspectRatio** members contain valid values. Otherwise, the pixel aspect ratios are unspecified.

### `SourceAspectRatio`

A [DXVAHD_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_rational) structure that contains the source PAR. The default state value is 1:1 (square pixels).

### `DestinationAspectRatio`

A [DXVAHD_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_rational) structure that contains the destination PAR. The default state value is 1:1 (square pixels).

## Remarks

Pixel aspect ratios of the form 0/*n* and *n*/0 are not valid.

If the **Enable** member is **FALSE**, the device ignores the values of **SourceAspectRatio** and **DestinationAspectRatio**.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Picture Aspect Ratio](https://learn.microsoft.com/windows/desktop/medfound/picture-aspect-ratio)