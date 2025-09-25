## Description

Describes Direct3D 11.1 feature options in the current graphics driver.

> [!NOTE]
> This structure is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

## Members

### `OutputMergerLogicOp`

Specifies whether logic operations are available in blend state. The runtime sets this member to **TRUE** if logic operations are available in blend state and **FALSE** otherwise. This member is **FALSE** for [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3. This member is optional for feature level 10, 10.1, and 11. This member is **TRUE** for feature level 11.1.

### `UAVOnlyRenderingForcedSampleCount`

Specifies whether the driver can render with no render target views (RTVs) or depth stencil views (DSVs), and only unordered access views (UAVs) bound. The runtime sets this member to **TRUE** if the driver can render with no RTVs or DSVs and only UAVs bound and **FALSE** otherwise. If **TRUE**, you can set the **ForcedSampleCount** member of [D3D11_RASTERIZER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-cd3d11_rasterizer_desc1) to 1, 4, or 8 when you render with no RTVs or DSV and only UAVs bound. For [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 11.1, this member is always **TRUE** and you can also set **ForcedSampleCount** to 16 in addition to 1, 4, or 8. The default value of **ForcedSampleCount** is 0, which means the same as if the value is set to 1. You can always set **ForcedSampleCount** to 0 or 1 for UAV-only rendering independently of how this member is set.

### `DiscardAPIsSeenByDriver`

Specifies whether the driver supports the [ID3D11DeviceContext1::DiscardView](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-discardview) and [ID3D11DeviceContext1::DiscardResource](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-discardresource) methods. The runtime sets this member to **TRUE** if the driver supports these methods and **FALSE** otherwise. How this member is set does not indicate whether the driver actually uses these methods; that is, the driver might ignore these methods if they are not useful to the hardware. If **FALSE**, the runtime does not expose these methods to the driver because the driver does not support them. You can monitor this member during development to rule out legacy drivers on hardware where these methods might have otherwise been beneficial. You are not required to write separate code paths based on whether this member is **TRUE** or **FALSE**; you can call these methods whenever applicable.

### `FlagsForUpdateAndCopySeenByDriver`

Specifies whether the driver supports new semantics for copy and update that are exposed by the [ID3D11DeviceContext1::CopySubresourceRegion1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-copysubresourceregion1) and [ID3D11DeviceContext1::UpdateSubresource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-updatesubresource1) methods. The runtime sets this member to **TRUE** if the driver supports new semantics for copy and update. The runtime sets this member to **FALSE** only for legacy drivers. The runtime handles this member similarly to the **DiscardAPIsSeenByDriver** member.

### `ClearView`

Specifies whether the driver supports the [ID3D11DeviceContext1::ClearView](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-clearview) method. The runtime sets this member to **TRUE** if the driver supports this method and **FALSE** otherwise. If **FALSE**, the runtime does not expose this method to the driver because the driver does not support it.

**Note** For [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3, this member is always **TRUE** because the option is emulated by the runtime.

### `CopyWithOverlap`

Specifies whether you can call [ID3D11DeviceContext1::CopySubresourceRegion1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-copysubresourceregion1) with overlapping source and destination rectangles. The runtime sets this member to **TRUE** if you can call **CopySubresourceRegion1** with overlapping source and destination rectangles and **FALSE** otherwise. If **FALSE**, the runtime does not expose this method to the driver because the driver does not support it.

**Note** For [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3, this member is always **TRUE** because drivers already support the option for these feature levels.

### `ConstantBufferPartialUpdate`

Specifies whether the driver supports partial updates of constant buffers. The runtime sets this member to **TRUE** if the driver supports partial updates of constant buffers and **FALSE** otherwise. If **FALSE**, the runtime does not expose this operation to the driver because the driver does not support it.

**Note** For [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3, this member is always **TRUE** because the option is emulated by the runtime.

### `ConstantBufferOffsetting`

Specifies whether the driver supports new semantics for setting offsets in constant buffers for a shader. The runtime sets this member to **TRUE** if the driver supports allowing you to specify offsets when you call new methods like the [ID3D11DeviceContext1::VSSetConstantBuffers1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-vssetconstantbuffers1) method and **FALSE** otherwise. If **FALSE**, the runtime does not expose this operation to the driver because the driver does not support it.

**Note** For [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3, this member is always **TRUE** because the option is emulated by the runtime.

### `MapNoOverwriteOnDynamicConstantBuffer`

Specifies whether you can call [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) with [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map) on a dynamic constant buffer (that is, whether the driver supports this operation). The runtime sets this member to **TRUE** if the driver supports this operation and **FALSE** otherwise. If **FALSE**, the runtime fails this method because the driver does not support the operation.

**Note** For [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3, this member is always **TRUE** because the option is emulated by the runtime.

### `MapNoOverwriteOnDynamicBufferSRV`

Specifies whether you can call [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) with [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map) on a dynamic buffer SRV (that is, whether the driver supports this operation). The runtime sets this member to **TRUE** if the driver supports this operation and **FALSE** otherwise. If **FALSE**, the runtime fails this method because the driver does not support the operation.

### `MultisampleRTVWithForcedSampleCountOne`

Specifies whether the driver supports multisample rendering when you render with RTVs bound. If **TRUE**, you can set the **ForcedSampleCount** member of [D3D11_RASTERIZER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-cd3d11_rasterizer_desc1) to 1 with a multisample RTV bound. The driver can support this option on [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 10 and higher. If **FALSE**, the rasterizer-state creation will fail because the driver is legacy or the feature level is too low.

### `SAD4ShaderInstructions`

Specifies whether the hardware and driver support the [msad4](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-msad4) intrinsic function in shaders. The runtime sets this member to **TRUE** if the hardware and driver support calls to **msad4** intrinsic functions in shaders. If **FALSE**, the driver is legacy or the hardware does not support the option; the runtime will fail shader creation for shaders that use **msad4**.

### `ExtendedDoublesShaderInstructions`

Specifies whether the hardware and driver support the [fma](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-fma) intrinsic function and other extended doubles instructions (**DDIV** and **DRCP**) in shaders. The **fma** intrinsic function emits an extended doubles **DFMA** instruction. The runtime sets this member to **TRUE** if the hardware and driver support extended doubles instructions in shaders ([shader model 5](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d11-graphics-reference-sm5) and higher). Support of this option implies support of basic double-precision shader instructions as well. You can use the [D3D11_FEATURE_DOUBLES](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature) value to query for support of double-precision shaders. If **FALSE**, the hardware and driver do not support the option; the runtime will fail shader creation for shaders that use extended doubles instructions.

### `ExtendedResourceSharing`

Specifies whether the hardware and driver have [extended support for shared Texture2D resource types and formats](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-1-features#extended-support-for-shared-texture2d-resources). The runtime sets this member to **TRUE** if the hardware and driver support extended Texture2D resource sharing.

## Remarks

If a Microsoft Direct3D device supports [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 11.1 ([D3D_FEATURE_LEVEL_11_1](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)), when you call [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) with [D3D11_FEATURE_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature), **CheckFeatureSupport** returns a pointer to **D3D11_FEATURE_DATA_D3D11_OPTIONS** with all member set to **TRUE** except the **SAD4ShaderInstructions** and **ExtendedDoublesShaderInstructions** members, which are optionally supported by the hardware and driver and therefore can be **TRUE** or **FALSE**.

[Feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 11.1 provides the following additional features:

* UAVs at every shader stage with 64 UAV bind slots instead of 8.
* Target-independent rasterization, which enables you to set the **ForcedSampleCount** member of [D3D11_RASTERIZER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-cd3d11_rasterizer_desc1) to 1, 4, 8, or 16 and to render to RTVs with a single sample.
* UAV-only rendering with the **ForcedSampleCount** member of [D3D11_RASTERIZER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-cd3d11_rasterizer_desc1) set to up to 16 (only up to 8 for [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 11).

The runtime always sets the following groupings of members identically. That is, all the values in a grouping are **TRUE** or **FALSE** together:

* **DiscardAPIsSeenByDriver** and **FlagsForUpdateAndCopySeenByDriver**
* **ClearView**, **CopyWithOverlap**, **ConstantBufferPartialUpdate**, **ConstantBufferOffsetting**, and **MapNoOverwriteOnDynamicConstantBuffer**
* **MapNoOverwriteOnDynamicBufferSRV** and **MultisampleRTVWithForcedSampleCountOne**

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)