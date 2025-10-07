# WaveActiveBallot function

Returns a uint4 containing a bitmask of the evaluation of the Boolean expression for all active lanes in the current wave.

## Parameters

*expr*

The boolean expression to evaluate.

## Return value

A uint4 containing a bitmask of the evaluation of the Boolean expression for all active lanes in the current wave. The least-significant bit corresponds to the lane with index zero. The bits corresponding to inactive lanes will be zero. The bits that are greater than or equal to [**WaveGetLaneCount**](https://learn.microsoft.com/windows/win32/direct3dhlsl/wavegetlanecount) will be zero.

## Remarks

Different GPUs have different SIMD processor widths (lane counts). Most of these **WaveXXX** functions are able to operate at level of abstraction where SIMD machine width is concealed. To maximize portability of code across GPUs, use the intrinsics that don’t rely on machine width. For example, use:

``` syntax
uint result = WaveActiveCountBits( bBit );
```

Instead of:

``` syntax
uint result = countbits( WaveActiveBallot( bBit ) );
```

This function is supported from shader model 6.0 in all shader stages.

## Examples

``` syntax
// get a bitwise representation of the number of currently active lanes:
uint4 waveBits = WaveActiveBallot( true ); // convert to bits
```

## See also

[Overview of Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/hlsl-shader-model-6-0-features-for-direct3d-12)

[Shader Model 6](https://learn.microsoft.com/windows/win32/direct3dhlsl/shader-model-6-0)

