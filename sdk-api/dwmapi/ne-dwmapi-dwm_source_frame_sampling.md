# DWM_SOURCE_FRAME_SAMPLING enumeration

## Description

Flags used by the [DwmSetPresentParameters](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetpresentparameters) function to specify the frame sampling type.

## Constants

### `DWM_SOURCE_FRAME_SAMPLING_POINT`

Use the first source frame that includes the first refresh of the output frame.

### `DWM_SOURCE_FRAME_SAMPLING_COVERAGE`

Use the source frame that includes the most refreshes of the output frame. In the case of multiple source frames with the same coverage, the last frame is used.

### `DWM_SOURCE_FRAME_SAMPLING_LAST`

The maximum recognized [DWM_SOURCE_FRAME_SAMPLING](https://learn.microsoft.com/windows/desktop/api/dwmapi/ne-dwmapi-dwm_source_frame_sampling) value, used for validation purposes.