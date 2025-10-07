# WaveActiveSum function

Sums up the value of the expression across all active lanes in the current wave and replicates it to all lanes in the current wave.

## Parameters

*expr*

The expression to evaluate.

## Return value

The sum value.

## Remarks

The order of operations is undefined.

This function is supported from shader model 6.0 in all shader stages.

## Examples

``` syntax
float3 total = WaveActiveSum( position ); // sum positions in wave
float3 center = total/count;           // compute average of these positions
```

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)

