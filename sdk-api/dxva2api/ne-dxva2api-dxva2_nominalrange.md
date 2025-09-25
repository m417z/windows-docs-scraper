# DXVA2_NominalRange enumeration

## Description

Describes how to map color data to a normalized [0...1] range.

These flags are used in the [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure. They indicate whether the range of color values includes headroom (values above 100% white) and toeroom (values below reference black).

## Constants

### `DXVA2_NominalRangeMask:0x7`

Bitmask to validate flag values. This value is not a valid flag.

### `DXVA2_NominalRange_Unknown:0`

Unknown or unspecified nominal range.

If this value is used in the **DestFormat** member of the [DXVA2_VideoProcessBltParams](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videoprocessbltparams) structure, the driver will determine the optimal nominal range based on the destination color space. For example, the destination surface is usually sRGB, which has a nominal range of 0-255 per channel. However, a driver might use a technique such as automatic gain control to maximize the dynamic range while preserving values above reference white.

### `DXVA2_NominalRange_Normal:1`

Equivalent to DXVA2_NominalRange_0_255.

### `DXVA2_NominalRange_Wide:2`

Equivalent to DXVA2_NominalRange_16_235.

### `DXVA2_NominalRange_0_255:1`

The normalized range [0...1] maps to [0...255] for 8-bit samples or [0...1023] for 10-bit samples.

### `DXVA2_NominalRange_16_235:2`

The normalized range [0...1] maps to [16...235] for 8-bit samples or [64...940] for 10-bit samples.

### `DXVA2_NominalRange_48_208:3`

The normalized range [0..1] maps to [48...208] for 8-bit samples or [192...832] for 10-bit samples.

## Remarks

For YUV colors, these flags specify how to convert between Y'CbCr and Y'PbPr. The Y'PbPr color space has a range of [0..1] for Y' (luma) and [-0.5...0.5] for Pb/Pr (chroma).

| Value | Description |
| --- | --- |
| DXVA2_NominalRange_0_255 | Should not be used for YUV data. |
| DXVA2_NominalRange_16_235 | For 8-bit Y'CbCr components:<br><br>* Y' range of [0...1] maps to [16..235] for 8-bit Y' values.<br>* Pb/Pr ranges of [-0.5...0.5] map to [16...240] for 8-bit Cb/Cr values.<br><br>For samples with *n* bits of precision, the general equations are:<br><br>* Y' = (Y' * 219 + 16) * 2 ^ (n-8)<br>* Cb = (Pb * 224 + 128) * 2 ^ (n-8)<br>* Cr = (Pr * 224 + 128) * 2 ^ (n-8)<br><br>The inverse equations to convert from Y'CbCr to Y'PbPr are:<br><br>* Y' = (Y' / 2 ^ (n-8) - 16) / 219<br>* Pb = (Cb / 2 ^ (n-8) - 128) / 224<br>* Pr = (Cr / 2 ^ (n-8) - 128) / 224 |
| DXVA2_NominalRange_48_208 | For 8-bit Y'CbCr values, Y' range of [0..1] maps to [48...208]. |

For RGB colors, the flags differentiate various RGB spaces.

| Value | Description |
| --- | --- |
| DXVA2_NominalRange_0_255 | sRGB |
| DXVA2_NominalRange_16_235 | Studio RGB; ITU-R BT.709 |
| DXVA2_NominalRange_48_208 | ITU-R BT.1361 RGB |

Video data might contain values above or below the nominal range.

**Note** The values named DXVA2_NominalRange_Normal and DXVA2_NominalRange_Wide are a potential source of confusion. *Wide* refers to the possible range of *analog* values that can be represented, by mapping the nominal range [0...1] into a narrower range of *digital* values. Because the meaning of *wide* in this context is ambiguous, the equivalent values named DXVA2_NominalRange_0_255 and DXVA2_NominalRange_16_235 are preferred. These names explicitly convey the meaning of the enumeration, and are less likely to be misinterpreted.

This enumeration is equivalent to the **DXVA_NominalRange** enumeration used in DXVA 1.0, although it defines additional values.

If you are using the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface to describe the video format, the nominal range is specified in the [MF_MT_VIDEO_NOMINAL_RANGE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-nominal-range-attribute) attribute.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)