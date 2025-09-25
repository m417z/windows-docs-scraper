# D3D11_FEATURE_DATA_D3D9_OPTIONS structure

## Description

**Note** This structure is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

Describes Direct3D 9 feature options in the current graphics driver.

## Members

### `FullNonPow2TextureSupport`

Specifies whether the driver supports the nonpowers-of-2-unconditionally feature. For more information about this feature, see [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro). The runtime sets this member to **TRUE** for hardware at Direct3D 10 and higher feature levels. For hardware at Direct3D 9.3 and lower feature levels, the runtime sets this member to **FALSE** if the hardware and driver support the powers-of-2 (2D textures must have widths and heights specified as powers of two) feature or the nonpowers-of-2-conditionally feature. For more information about this feature, see feature level.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)