# D3D12_VIDEO_FRAME_STEREO_FORMAT enumeration

## Description

Defines the layout in memory of a stereo 3D video frame. All drivers that support stereo must support all of the defined formats.

## Constants

### `D3D12_VIDEO_FRAME_STEREO_FORMAT_NONE`

No stereo format is specified.

### `D3D12_VIDEO_FRAME_STEREO_FORMAT_MONO`

The sample does not contain stereo data. If the stereo format is not specified, this value is the default.

### `D3D12_VIDEO_FRAME_STEREO_FORMAT_HORIZONTAL`

Frame 0 and frame 1 are packed side-by-side, as shown in the following diagram.

![Horizontal stereo format showing the frame 0 pixels on the left of a grid of pixels and the frame 1 pixels on the right](https://learn.microsoft.com/windows/win32/api/d3d12video/images/stereo_format_horizontal.png)

### `D3D12_VIDEO_FRAME_STEREO_FORMAT_VERTICAL`

Frame 0 and frame 1 are packed top-to-bottom, as shown in the following diagram.

![Vertical stereo format showing the frame 0 pixels on the top of a grid of pixels and the frame 1 pixels on the bottom](https://learn.microsoft.com/windows/win32/api/d3d12video/images/stereo_format_horizontal.png)

### `D3D12_VIDEO_FRAME_STEREO_FORMAT_SEPARATE`

Frame 0 and frame 1 are placed in separate resources

## Remarks

## See also