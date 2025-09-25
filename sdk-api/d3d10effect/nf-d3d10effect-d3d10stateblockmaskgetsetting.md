# D3D10StateBlockMaskGetSetting function

## Description

Get an element in a state-block mask; determine if an element is allowed by the mask for capturing and applying.

## Parameters

### `pMask` [in]

Type: **[D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask)***

State block mask. See [D3D10_STATE_BLOCK_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ns-d3d10effect-d3d10_state_block_mask).

### `StateType` [in]

Type: **[D3D10_DEVICE_STATE_TYPES](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ne-d3d10effect-d3d10_device_state_types)**

The type of device state. See [D3D10_DEVICE_STATE_TYPES](https://learn.microsoft.com/windows/desktop/api/d3d10effect/ne-d3d10effect-d3d10_device_state_types).

### `Entry` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The entry within the device state. This is only relevant for state types that have more than one entry, such as D3D10_DST_GS_SAMPLERS.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns true if the specified feature is allowed by the mask for capturing and applying, and false otherwise.

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)

[Effect Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-functions)