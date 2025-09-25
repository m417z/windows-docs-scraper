# _D3DDDI_HDR_METADATA_HDR10 structure

## Description

Describes the metadata for HDR10.

## Members

### `RedPrimary`

The chromaticity coordinates of the red color primary in the CIE xy color space. Index 0 contains the X coordinate and index 1 contains the Y coordinate. Values are normalized to 50,000.

### `GreenPrimary`

The chromaticity coordinates of the green color primary in the CIE xy color space. Index 0 contains the x coordinate and index 1 contains the y coordinate. Values are normalized to 50,000.

### `BluePrimary`

The chromaticity coordinates of the blue color primary in the CIE xy color space. Index 0 contains the x coordinate and index 1 contains the y coordinate. Values are normalized to 50,000.

### `WhitePoint`

The chromaticity coordinates of the white point in the CIE xy color space. Index 0 contains the x coordinate and index 1 contains the y coordinate. Values are normalized to 50,000.

### `MaxMasteringLuminance`

The maximum number of nits of the display used to master the content. Values are in whole nits.

### `MinMasteringLuminance`

The minimum number of nits of the display used to master the content. Values are in 1/10000th of a nit (0.0001 nits).

### `MaxContentLightLevel`

The maximum content light level (MaxCLL). This is the nit value corresponding to the brightest pixel used anywhere in the content.

### `MaxFrameAverageLightLevel`

The maximum frame average light level (MaxFALL). This is the nit value corresponding to the average luminance of the frame which has the brightest average luminance anywhere in the content.

## Remarks

D3DDDI_HDR_METADATA_HDR10 has equivalent definitions to DXGI_HDR_METADATA_HDR10.