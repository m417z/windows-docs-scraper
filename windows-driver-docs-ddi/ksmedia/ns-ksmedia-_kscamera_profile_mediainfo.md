# _KSCAMERA_PROFILE_MEDIAINFO structure

## Description

This structure contains the relevant media type information presented for each camera profile.

## Members

### `Resolution`

The X (horizontal) and Y (vertical) frame size in pixels.

### `Resolution.X`

### `Resolution.Y`

### `MaxFrameRate`

The numerator/denominator ratio of frame rate (for example, 30 / 1 = 30fps). This frame rate represents the maximum frame rate of the specified resolution under ideal lighting conditions. Actual frame rate may be lower than this value.

For photo media information, if photo sequence cannot be enabled because of hardware constraints for the given photo resolution, the frame rate must be set to 0 (numerator=0, denominator=0). This will inform the application layer that photo sequence control will be rejected by the driver when that particular photo media type is selected.

### `MaxFrameRate.Numerator`

### `MaxFrameRate.Denominator`

### `Flags`

The bitwise OR of one or more of the following flags:

* KSCAMERAPROFILE_FLAGS_VIDEOHDRWhen the video HDR flag is set for the media info, for that media setting, video HDR may be enabled for the record stream.

  This flag may not be set for media info on the photo pin.
* KSCAMERAPROFILE_FLAGS_VARIABLEPHOTOSEQUENCEWhen the Variable Photo Sequence flag is set for the media info, VPS support is available even if the photo media info does not provide a frame rate.

  If this flag is set and the frame rate is non-zero, for that photo media info, VPS and Photo Sequence is available.

  If this flag is set and the frame rate is zero, for that photo media info, VPS is available but not Photo Sequence.

  If this flag is not set and the frame rate is non-zero, for that photo media info, VPS is not available but Photo Sequence is available.

  If this flag is not set and the frame rate is zero, neither VPS nor Photo Sequence is available for that media info.

  This flag may only be set for media info on the photo pin. Presence of this flag on non-photo pin media info will result in the profile set being rejected.

### `Data0`

Reserved. Must be set to 0.

### `Data1`

Reserved. Must be set to 0.

### `Data2`

Reserved. Must be set to 0.

### `Data3`

Reserved. Must be set to 0.