# WavePrefixSum function

Returns the sum of all of the values in the active lanes with smaller indices than this one.

## Parameters

*value*

The value to sum up.

## Return value

The sum of the values.

## Remarks

The order of operations on this routine cannot be guaranteed. So, effectively, the \[precise\] flag is ignored within it.

A postfix sum can be computed by adding the prefix sum to the current lane's value.

Note that the active lane with the lowest index will always receive a 0 for its prefix sum.

This function is supported from shader model 6.0 in all shader stages.

## Examples

```hlsl
uint numToSum = 2;
uint prefixSum = WavePrefixSum( numToSum );
```

On a machine with a wave size of 8, and all lanes active except lanes 0 and 4, the following values would be returned from WavePrefixSum.

| lane index | status | prefixSum |
|------------|----------|---------------|
| 0 | inactive | n/a |
| 1 | active | = 0 |
| 2 | active | = 0+2 |
| 3 | active | = 0+2+2 |
| 4 | inactive | n/a |
| 5 | active | = 0+2+2+2 |
| 6 | active | = 0+2+2+2+2 |
| 7 | active | = 0+2+2+2+2+2 |

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)