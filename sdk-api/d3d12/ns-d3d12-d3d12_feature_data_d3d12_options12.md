## Description

Indicates whether or not Enhanced Barriers are supported.

## Members

### `MSPrimitivesPipelineStatisticIncludesCulledPrimitives`

Type: \_Out\_ **[D3D12_TRI_STATE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_tri_state)**

TBD

### `EnhancedBarriersSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Indicates whether or not Enhanced Barriers are supported. `true` if supported, otherwise `false`.

Enhanced Barriers is not currently a hardware or driver requirement. So before using command list Barrier APIs, or resource creation APIs using the *InitialLayout* parameter, you must check for optional driver support via *EnhancedBarriersSupported*.

Requires the DirectX 12 Agility SDK 1.7 or later; otherwise, the value is always `FALSE`.

### `RelaxedFormatCastingSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Technically used to indicate support for the functionality that enables integer aliasing.

Requires the DirectX 12 Agility SDK 1.7 or later; otherwise, the value is always `FALSE`.

## Remarks

## See also