# D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_0020 enumeration

## Description

Defines the layout in memory of a stereo 3D video frame.

## Constants

### `D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_0020_MONO`

The sample does not contain stereo data. If the stereo format is not specified, this value is the default.

### `D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_0020_HORIZONTAL`

Frame 0 and frame 1 are packed side-by-side, as shown in the following diagram:

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 1 | 1 | 1 |
| 0 | 0 | 0 | 1 | 1 | 1 |
| 0 | 0 | 0 | 1 | 1 | 1 |
| 0 | 0 | 0 | 1 | 1 | 1 |

### `D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_0020_VERTICAL`

Frame 0 and frame 1 are packed top-to-bottom, as shown in the following diagram:

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 |

### `D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_0020_SEPARATE`

Frame 0 and frame 1 are placed in separate resources.

## Remarks

All drivers that support stereo must support all the formats in this enumeration.