# WaveActiveAllEqual function

Returns true if the expression is the same for every active lane in the current wave (and thus uniform across it).

## Parameters

*expr*

The expression to evaluate.
`` can be a basic scalar, vector, or matrix type.

## Return value

Returns `true` for each component of `expr` that is the same for every active lane in the current wave.

`` will be a scalar, vector, or matrix of `bool`, matching the dimensionality of the input ``.
For instance, an input `` of `matrix` will result in a return `` of `matrix`.

## Remarks

This function is supported from shader model 6.0 in all shader stages.

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)

