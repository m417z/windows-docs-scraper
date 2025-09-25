# D3D10StateBlockMaskUnion function

## Description

Combine two state-block masks with a bitwise OR.

## Parameters

### `pA` [in]

Type: **[D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask)***

State block mask on the left side of the bitwise OR operation. See [D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask).

### `pB` [in]

Type: **[D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask)***

State block mask on the right side of the bitwise OR operation.

### `pResult` [out]

Type: **[D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask)***

The result of the bitwise OR operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)

[Effect Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-functions)