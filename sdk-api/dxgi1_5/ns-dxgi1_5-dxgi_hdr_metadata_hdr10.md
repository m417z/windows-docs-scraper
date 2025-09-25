# DXGI_HDR_METADATA_HDR10 structure

## Description

Describes the metadata for HDR10, used when video is compressed using High Efficiency Video Coding (HEVC). This is used to describe the capabilities of the display used to master the content and the luminance values of the content.

## Members

### `RedPrimary`

The chromaticity coordinates of the red value in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000.

### `GreenPrimary`

The chromaticity coordinates of the green value in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000.

### `BluePrimary`

The chromaticity coordinates of the blue value in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000.

### `WhitePoint`

The chromaticity coordinates of the white point in the CIE1931 color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. The values are normalized to 50,000.

### `MaxMasteringLuminance`

The maximum number of nits of the display used to master the content. Values are in whole nits.

### `MinMasteringLuminance`

The minimum number of nits of the display used to master the content. Values are 1/10000th of a nit (0.0001 nit).

### `MaxContentLightLevel`

The maximum content light level (MaxCLL). This is the nit value corresponding to the brightest pixel used anywhere in the content.

### `MaxFrameAverageLightLevel`

The maximum frame average light level (MaxFALL). This is the nit value corresponding to the average luminance of the frame which has the brightest average luminance anywhere in the content.

## Remarks

This structure represents the definition of HDR10 metadata used with HEVC, not HDR10 metadata for ST.2086. These are closely related but defined differently.

Example: Mastering display with DCI-P3 color primaries and D65 white point, maximum luminance of 1000 nits and minimum luminance of 0.001 nits; content has maximum luminance of 2000 nits and maximum frame average light level (MaxFALL) of 500 nits.

```cpp
RedPrimary[0] = 0.680 * 50000;
RedPrimary[1] = 0.320 * 50000;
GreenPrimary[0] = 0.265 * 50000;
GreenPrimary[1] = 0.690 * 50000;
BluePrimary[0] = 0.150 * 50000;
BluePrimary[1] = 0.060 * 50000;
WhitePoint[0] = 0.3127 * 50000;
WhitePoint[1] = 0.3290 * 50000;
MaxMasteringLuminance = 1000;
MinMasteringLuminance = 0.001 * 10000;
MaxContentLightLevel = 2000;
MaxFrameAverageLightLevel = 500;
```

This structure is used in conjunction with the [SetHDRMetaData](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgiswapchain4-sethdrmetadata) method.

## See also

[DXGI 1.5 Improvements](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-1-5-improvements)

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)