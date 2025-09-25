# D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT structure

## Description

**Note** This structure is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

Describes Direct3D 9 shadow support in the current graphics driver.

## Members

### `SupportsDepthAsTextureWithLessEqualComparisonFilter`

Specifies whether the driver supports the shadowing feature with the comparison-filtering mode set to less than or equal to. The runtime sets this member to **TRUE** for hardware at Direct3D 10 and higher [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro). For hardware at Direct3D 9.3 and lower feature levels, the runtime sets this member to **TRUE** only if the hardware and driver support the shadowing feature; otherwise **FALSE**.

## Remarks

Shadows are an important element in realistic 3D scenes. You can use the shadow buffer technique to render shadows. The basic principle of the technique is to use a depth buffer to store the scene depth info from the perspective of the light source, and then compare each point rendered in the scene with that buffer to determine if it is in shadow.

To render objects into the scene with shadows on them, you create [sampler state objects](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-sampler) with comparison filtering set and the comparison mode (ComparisonFunc) to LessEqual. You can also set BorderColor addressing on this depth sampler, even though BorderColor isn't typically allowed on [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1 and 9.2. By using the border color and picking 0.0 or 1.0 as the border color value, you can control whether the regions off the edge of the shadow map appear to be always in shadow or never in shadow respectively.
You can control the shadow filter quality by the Mag and Min filter settings in the comparison sampler. Point sampling will produce shadows with non-anti-aliased edges. Linear filter sampler settings will result in higher quality shadow edges, but might affect performance on some power-optimized devices.

**Note** If you use a separate setting for Mag versus Min filter options, you produce an undefined result. Anisotropic filtering is not supported. The Mip filter choice is not relevant because [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.x does not allow mipmapped depth buffers.

**Note** On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.x, you can't compile a shader with the [SampleCmp](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmp) and [SampleCmpLevelZero](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmplevelzero) intrinsic functions by using older versions of the compiler. For example, you can't use the [fxc.exe](https://learn.microsoft.com/windows/desktop/direct3dtools/fxc) compiler that ships with the DirectX SDK or use the **D3DCompile**** functions (like [D3DCompileFromFile](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompilefromfile)) that are implemented in D3DCompiler_43.dll and earlier. These intrinsic functions on feature level 9.x are only supported in the fxc.exe compiler that ships with the Windows 8 SDK and later and with the **D3DCompile**** functions that are implemented in D3DCompiler_44.dll and later.
But these intrinsic functions are present in shader models for feature levels higher than 9.x.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)