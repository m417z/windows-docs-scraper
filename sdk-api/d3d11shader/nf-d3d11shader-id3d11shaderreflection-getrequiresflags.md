# ID3D11ShaderReflection::GetRequiresFlags

## Description

Gets a group of flags that indicates the requirements of a shader.

## Return value

Type: **UINT64**

A value that contains a combination of one or more shader requirements flags; each flag specifies a requirement of the shader. A default value of 0 means there are no requirements.

| Shader requirement flag | Description |
| --- | --- |
| **D3D_SHADER_REQUIRES_DOUBLES** | Shader requires that the graphics driver and hardware support double data type. For more info, see [D3D11_FEATURE_DATA_DOUBLES](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_doubles). |
| **D3D_SHADER_REQUIRES_EARLY_DEPTH_STENCIL** | Shader requires an early depth stencil. |
| **D3D_SHADER_REQUIRES_UAVS_AT_EVERY_STAGE** | Shader requires unordered access views (UAVs) at every pipeline stage. |
| **D3D_SHADER_REQUIRES_64_UAVS** | Shader requires 64 UAVs. |
| **D3D_SHADER_REQUIRES_MINIMUM_PRECISION** | Shader requires the graphics driver and hardware to support minimum precision. For more info, see [Using HLSL minimum precision](https://learn.microsoft.com/windows/desktop/direct3dhlsl/using-hlsl-minimum-precision). |
| **D3D_SHADER_REQUIRES_11_1_DOUBLE_EXTENSIONS** | Shader requires that the graphics driver and hardware support extended doubles instructions. For more info, see the **ExtendedDoublesShaderInstructions** member of [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options). |
| **D3D_SHADER_REQUIRES_11_1_SHADER_EXTENSIONS** | Shader requires that the graphics driver and hardware support the [msad4](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-msad4) intrinsic function in shaders. For more info, see the **SAD4ShaderInstructions** member of [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options). |
| **D3D_SHADER_REQUIRES_LEVEL_9_COMPARISON_FILTERING** | Shader requires that the graphics driver and hardware support Direct3D 9 shadow support. For more info, see [D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d9_shadow_support). |
| **D3D_SHADER_REQUIRES_TILED_RESOURCES** | Shader requires that the graphics driver and hardware support tiled resources. For more info, see [GetResourceTiling](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11device2-getresourcetiling). |

## Remarks

Here is how the D3D11Shader.h header defines the shader requirements flags:

```cpp

#define D3D_SHADER_REQUIRES_DOUBLES                         0x00000001
#define D3D_SHADER_REQUIRES_EARLY_DEPTH_STENCIL             0x00000002
#define D3D_SHADER_REQUIRES_UAVS_AT_EVERY_STAGE             0x00000004
#define D3D_SHADER_REQUIRES_64_UAVS                         0x00000008
#define D3D_SHADER_REQUIRES_MINIMUM_PRECISION               0x00000010
#define D3D_SHADER_REQUIRES_11_1_DOUBLE_EXTENSIONS          0x00000020
#define D3D_SHADER_REQUIRES_11_1_SHADER_EXTENSIONS          0x00000040
#define D3D_SHADER_REQUIRES_LEVEL_9_COMPARISON_FILTERING    0x00000080

```

## See also

[ID3D11ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection)