# QuadReadLaneAt function

Returns the specified source value from the lane identified by the lane ID within the current quad.

## Parameters

*sourceValue*

The requested type.

*quadLaneID*

The lane ID; this will be a value from 0 to 3.

## Return value

The specified source value. The result of this function is uniform across the quad. If the source lane is inactive, the results are undefined.

## Remarks

For more information on quads, refer to [Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12).

This function is supported from shader model 6.0 only in pixel and compute shaders.

## See also

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)

