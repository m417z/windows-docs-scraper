# DXVAHD_CONTENT_DESC structure

## Description

Describes a video stream for a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

The display driver can use the information in this structure to optimize the capabilities of the video processor. For example, some capabilities might not be exposed for high-definition (HD) content, for performance reasons.

## Members

### `InputFrameFormat`

A member of the [DXVAHD_FRAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_frame_format) enumeration that describes how the video stream is interlaced.

### `InputFrameRate`

The frame rate of the input video stream, specified as a [DXVAHD_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_rational) structure.

### `InputWidth`

The width of the input frames, in pixels.

### `InputHeight`

The height of the input frames, in pixels.

### `OutputFrameRate`

The frame rate of the output video stream, specified as a [DXVAHD_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_rational) structure.

### `OutputWidth`

The width of the output frames, in pixels.

### `OutputHeight`

The height of the output frames, in pixels.

## Remarks

Frame rates are expressed as ratios. For example, 30 frames per second (fps) is expressed as 30:1, and 29.97 fps is expressed as 30000/1001. For interlaced content, a frame consists of two fields, so that the frame rate is half the field rate.

 If the application will composite two or more input streams, use the largest stream for the values of **InputWidth** and **InputHeight**.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)