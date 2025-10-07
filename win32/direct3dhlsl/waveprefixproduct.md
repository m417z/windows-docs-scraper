# WavePrefixProduct function

Returns the product of all of the values in the active lanes in this wave with indices less than this lane.

## Parameters

*value*

The value to multiply.

## Return value

The product of all the values.

## Remarks

The order of operations on this routine cannot be guaranteed. So, effectively, the \[precise\] flag is ignored within it.

A postfix product can be computed by multiplying the prefix product by the current lane's value.

Note that the active lane with the lowest index will always receive a 1 for its prefix product.

This function is supported from shader model 6.0 in all shader stages.

## Examples

```hlsl
uint numToMultiply = 2;
uint prefixProduct = WavePrefixProduct( numToMultiply );
```

On a machine with a wave size of 8, and all lanes active except lanes 0 and 4, the following values would be returned from WavePrefixProduct.

| lane index | status | prefixProduct |
|------------|----------|---------------|
| 0 | inactive | n/a |
| 1 | active | = 1 |
| 2 | active | = 1\*2 |
| 3 | active | = 1\*2\*2 |
| 4 | inactive | n/a |
| 5 | active | = 1\*2\*2\*2 |
| 6 | active | = 1\*2\*2\*2\*2 |
| 7 | active | = 1\*2\*2\*2\*2\*2 |

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)