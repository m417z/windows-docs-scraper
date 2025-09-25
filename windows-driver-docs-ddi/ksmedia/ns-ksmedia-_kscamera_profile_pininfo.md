# _KSCAMERA_PROFILE_PININFO structure

## Description

This structure specifies the available list of media types for each of the camera driver pins.

## Members

### `PinCategory`

This is the PINNAME category corresponding to Capture, Preview or Still image pin. For Windows 10, the only supported pin categories are: PINNAME_VIDEO_CAPTURE, PINNAME_VIDEO_PREVIEW, PINNAME_VIDEO_STILL. All other categories will result in an STATUS_INVALID_PARAMETER error.

### `PinIndex`

### `ProfileSensorType`

### `Reserved`

Unused. Must be 0.

### `MediaInfoCount`

Array size of KSCAMERA_PROFILE_MEDIAINFO structures specified in the MediaInfos field.

### `MediaInfos`

Array of KSCAMERA_PROFILE_MEDIAINFO structures.