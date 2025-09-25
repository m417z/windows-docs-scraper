# D3D12DDI_VIDEO_PROCESS_INPUT_STREAM_FLAGS_0020 enumeration

## Description

Input stream flags.

## Constants

### `D3D12DDI_VIDEO_PROCESS_INPUT_STREAM_FLAG_0020_NONE`

No flags specified.

### `D3D12DDI_VIDEO_PROCESS_INPUT_STREAM_FLAG_0020_FRAME_DISCONTINUITY`

The application must set this flag when not processing frames in order, such as seeking between frames. This should be a hint that cached filter processing from previous calls to process frames is invalid.

### `D3D12DDI_VIDEO_PROCESS_INPUT_STREAM_FLAG_0020_FRAME_REPEAT`

The application must set this flag when it applies video process operations to the same set of inputs. For example, paused video where the window is being resized causing a scale.