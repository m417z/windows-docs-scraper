# WaveGetLaneCount function

Returns the number of lanes in a wave on this architecture.

## Parameters

This function has no parameters.

## Return value

The result will be between 4 and 128, and includes all waves: active, inactive, and/or helper lanes. The result returned from this function may vary significantly depending on the driver implementation.

## Remarks

This function is supported from shader model 6.0 in all shader stages.

## Examples

``` syntax
 uint laneCount = WaveGetLaneCount();    // number of lanes in wave
```

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)

