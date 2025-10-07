# WaveReadLaneAt function

Returns the value of the expression for the given lane index within the specified wave.

## Parameters

*expr*

The expression to evaluate.

*laneIndex*

The index of the lane for which the *expr* result will be returned.

## Return value

The resulting value is the result of *expr*. It will be uniform if *laneIndex* is uniform.

## Remarks

If *laneIndex* is uniform, then this is effectively a broadcast operation; otherwise, it's a shuffle operation.

The result is undefined on a helper lane, or if the lane referred to by *laneIndex* is inactive or a helper lane.

This function is supported from shader model 6.0 in all shader stages.

## See also

* [Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)
* [Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)