# D3D11_FEATURE_DATA_DOUBLES structure

## Description

Describes double data type support in the current graphics driver.

## Members

### `DoublePrecisionFloatShaderOps`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether [double](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-scalar) types are allowed. If **TRUE**, [double](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-scalar) types are allowed; otherwise **FALSE**. The runtime must set **DoublePrecisionFloatShaderOps** to **TRUE** in order for you to use any [HLSL](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl) shader that is compiled with a [double](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-scalar) type.

## Remarks

If the runtime sets **DoublePrecisionFloatShaderOps** to **TRUE**, the hardware and driver support the following [Shader Model 5](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d11-graphics-reference-sm5) instructions:

* [dadd](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dadd---sm5---asm-)
* [dmax](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dmax--sm5---asm-)
* [dmin](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dmin--sm5---asm-)
* [dmul](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dmul--sm5---asm-)
* [deq](https://learn.microsoft.com/windows/desktop/direct3dhlsl/deq--sm5---asm-)
* [dge](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dge--sm5---asm-)
* [dlt](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dlt--sm5---asm-)
* [dne](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dne--sm5---asm-)
* [dmov](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dmov--sm5---asm-)
* [dmovc](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dmovc--sm5---asm-)
* [dtof](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dtof--sm5---asm-)
* [ftod](https://learn.microsoft.com/windows/desktop/direct3dhlsl/ftod--sm5---asm-)

**Note** If **DoublePrecisionFloatShaderOps** is **TRUE**, the hardware and driver do not necessarily support double-precision division.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)