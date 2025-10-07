# abort function

Submits an error message to the information queue and terminates the current draw or dispatch call being executed.

## Parameters

None

## Return value

This function does not return a value.

## Remarks

This operation does nothing on rasterizers that do not support it.

### Minimum Shader Model

This function is supported in the following shader models.

| Shader Model | Supported |
|---------------------------------------------------------------------|-----------|
| [Shader Model 4 (DirectX HLSL) or later.](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-sm3) | yes |

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------------------------|
| Header<br> | Corecrt\_terminate.h |

## See also

[Intrinsic Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)

