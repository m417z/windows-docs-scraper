# MFNominalRange enumeration

## Description

Specifies whether color data includes headroom and toeroom. Headroom allows for values beyond 1.0 white ("whiter than white"), and toeroom allows for values below reference 0.0 black ("blacker than black").

## Constants

### `MFNominalRange_Unknown:0`

Unknown nominal range.

### `MFNominalRange_Normal:1`

Equivalent to MFNominalRange_0_255.

### `MFNominalRange_Wide:2`

Equivalent to MFNominalRange_16_235.

### `MFNominalRange_0_255:1`

The normalized range [0...1] maps to [0...255] for 8-bit samples or [0...1023] for 10-bit samples.

### `MFNominalRange_16_235:2`

The normalized range [0...1] maps to [16...235] for 8-bit samples or [64...940] for 10-bit samples.

### `MFNominalRange_48_208:3`

The normalized range [0..1] maps to [48...208] for 8-bit samples or [64...940] for 10-bit samples.

### `MFNominalRange_64_127:4`

The normalized range [0..1] maps to [64...127] for 8-bit samples or [256...508] for 10-bit samples. This range is used in the xRGB color space.

**Note** Requires Windows 7 or later.

### `MFNominalRange_Last`

### `MFNominalRange_ForceDWORD:0x7fffffff`

## Remarks

This enumeration is used with the [MF_MT_VIDEO_NOMINAL_RANGE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-nominal-range-attribute) attribute.

For more information about these values, see the remarks for the [DXVA2_NominalRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_nominalrange) enumeration, which is the DirectX Video Acceleration (DXVA) equivalent of this enumeration.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)