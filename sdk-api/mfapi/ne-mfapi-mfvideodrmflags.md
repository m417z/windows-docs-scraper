# MFVideoDRMFlags enumeration

## Description

Specifies the type of copy protection required for a video stream.

## Constants

### `MFVideoDRMFlag_None:0`

No copy protection is required.

### `MFVideoDRMFlag_AnalogProtected:1`

Analog copy protection should be applied.

### `MFVideoDRMFlag_DigitallyProtected:2`

Digital copy protection should be applied.

## Remarks

Use these flags with the [MF_MT_DRM_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-drm-flags-attribute) attribute.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)