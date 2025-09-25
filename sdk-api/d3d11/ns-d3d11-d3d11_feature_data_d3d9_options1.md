# D3D11_FEATURE_DATA_D3D9_OPTIONS1 structure

## Description

**Note** This structure is supported by the Direct3D 11.2 runtime, which is available on Windows 8.1 and later operating systems.

Describes Direct3D 9 feature options in the current graphics driver.

## Members

### `FullNonPow2TextureSupported`

Specifies whether the driver supports the nonpowers-of-2-unconditionally feature. For more info about this feature, see [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro). The runtime sets this member to **TRUE** for hardware at Direct3D 10 and higher feature levels. For hardware at Direct3D 9.3 and lower feature levels, the runtime sets this member to **FALSE** if the hardware and driver support the powers-of-2 (2D textures must have widths and heights specified as powers of two) feature or the nonpowers-of-2-conditionally feature.

### `DepthAsTextureWithLessEqualComparisonFilterSupported`

Specifies whether the driver supports the shadowing feature with the comparison-filtering mode set to less than or equal to. The runtime sets this member to **TRUE** for hardware at Direct3D 10 and higher [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro). For hardware at Direct3D 9.3 and lower feature levels, the runtime sets this member to **TRUE** only if the hardware and driver support the shadowing feature; otherwise **FALSE**.

### `SimpleInstancingSupported`

Specifies whether the hardware and driver support simple instancing. The runtime sets this member to **TRUE** if the hardware and driver support simple instancing.

### `TextureCubeFaceRenderTargetWithNonCubeDepthStencilSupported`

Specifies whether the hardware and driver support setting a single face of a [TextureCube](https://learn.microsoft.com/windows/desktop/direct3dhlsl/texturecube) as a render target while the depth stencil surface that is bound alongside can be a [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d) (as opposed to **TextureCube**). The runtime sets this member to **TRUE** if the hardware and driver support this feature; otherwise **FALSE**.

If the hardware and driver don't support this feature, the app must match the render target surface type with the depth stencil surface type. Because hardware at Direct3D 9.3 and lower [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) doesn't allow [TextureCube](https://learn.microsoft.com/windows/desktop/direct3dhlsl/texturecube) depth surfaces, the only way to render a scene into a **TextureCube** while having depth buffering enabled is to render each **TextureCube** face separately to a [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d) render target first (because that can be matched with a **Texture2D** depth), and then copy the results into the **TextureCube**. If the hardware and driver support this feature, the app can just render to the **TextureCube** faces directly while getting depth buffering out of a **Texture2D** depth buffer.

You only need to query this feature from hardware at Direct3D 9.3 and lower [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) because hardware at Direct3D 10.0 and higher feature levels allow [TextureCube](https://learn.microsoft.com/windows/desktop/direct3dhlsl/texturecube) depth surfaces.

## Remarks

You can use the [D3D11_FEATURE_D3D9_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature) enumeration value with [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) to query a driver about support for Direct3D 9 feature options rather than making multiple calls to **ID3D11Device::CheckFeatureSupport** by using [D3D11_FEATURE_D3D9_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature), **D3D11_FEATURE_D3D9_SHADOW_SUPPORT**, and **D3D11_FEATURE_D3D9_SIMPLE_INSTANCING_SUPPORT**, which provide identical info about supported Direct3D 9 feature options.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)