# WaveActiveMax function

Returns the maximum value of the expression across all active lanes in the current wave and replicates it back to all active lanes.

## Parameters

*expr*

The expression to evaluate.

## Return value

The maximum value.

## Remarks

The order of operations is undefined.

This function is supported from shader model 6.0 in all shader stages.

## Examples

``` syntax
 float3 maxPos = WaveActiveMax( myPoint.position );
    BoundingBox.max = max( maxPos, BoundingBox.max );
```

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)

