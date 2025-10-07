# WaveActiveCountBits function

Counts the number of boolean variables which evaluate to true across all active lanes in the current wave, and replicates the result to all lanes in the wave.

## Parameters

*bBit*

The boolean variables to evaluate. Providing an explicit true Boolean value returns the number of active lanes.

## Return value

The number of lanes for which the boolean variable evaluates to true, across all active lanes in the current wave.

## Remarks

This function is supported from shader model 6.0 in all shader stages.

## Examples

This can be implemented more efficiently than a full WaveActiveSum, as described in the following example:

``` syntax
result = WaveActiveCountBits( WaveActiveBallot( bBit ) );
```

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)

