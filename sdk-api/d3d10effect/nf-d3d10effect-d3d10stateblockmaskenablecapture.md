# D3D10StateBlockMaskEnableCapture function

## Description

Enable a range of state values in a state block mask.

## Parameters

### `pMask` [in, out]

Type: **[D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask)***

A state block mask (see [D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask)).

### `StateType` [in]

Type: **[D3D10_DEVICE_STATE_TYPES](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ne-d3d10effect-d3d10_device_state_types)**

The type of device state to enable (see [D3D10_DEVICE_STATE_TYPES](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ne-d3d10effect-d3d10_device_state_types).

### `RangeStart` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The lower end of the range of values to set to true.

### `RangeLength` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The upper end of the range of values to set to true.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This is an example of how to call this function. It create a mask that can capture and apply to geometry-shader samplers in slots 2 ~ 13.

```

D3D10_STATE_BLOCK_MASK stateBlockMask;
D3D10StateBlockMaskEnableCapture(&stateBlockMask,
                                 D3D10_DST_GS_SAMPLERS,
                                 2, 13);

```

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)

[Effect Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-functions)