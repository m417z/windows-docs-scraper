# D3D10CreateStateBlock function

## Description

Create a state block.

## Parameters

### `pDevice` [in]

Type: **[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)***

The device for which the state block will be created.

### `pStateBlockMask` [in]

Type: **[D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask)***

Indicates which parts of the device state will be captured when calling [ID3D10StateBlock::Capture](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10stateblock-capture) and reapplied when calling [ID3D10StateBlock::Apply](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10stateblock-apply). See remarks.

### `ppStateBlock` [out]

Type: **[ID3D10StateBlock](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10stateblock)****

Address of a pointer to the buffer created (see [ID3D10StateBlock Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10stateblock)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

A state block is a collection of device state, and is used for saving and restoring device state. Use a state-block mask to enable subsets of state for saving and restoring.

The [D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask) structure can be filled manually or by using any of the D3D10StateBlockMaskXXX APIs. A state block mask can also be obtained by calling [ID3D10EffectTechnique::ComputeStateBlockMask](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effecttechnique-computestateblockmask) or [ID3D10EffectPass::ComputeStateBlockMask](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectpass-computestateblockmask).

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>In Direct3D 10, a state block object does not contain any valid information about the state of the device until [ID3D10StateBlock::Capture](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10stateblock-capture) is called. In Direct3D 9, state is saved in a state block object, when it is created. |

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)

[Effect Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-functions)