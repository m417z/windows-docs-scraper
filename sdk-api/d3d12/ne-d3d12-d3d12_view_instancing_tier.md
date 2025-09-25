# D3D12_VIEW_INSTANCING_TIER enumeration

## Description

Indicates the tier level at which view instancing is supported.

## Constants

### `D3D12_VIEW_INSTANCING_TIER_NOT_SUPPORTED:0`

View instancing is not supported.

### `D3D12_VIEW_INSTANCING_TIER_1:1`

View instancing is supported by draw-call level looping only.

### `D3D12_VIEW_INSTANCING_TIER_2:2`

View instancing is supported by draw-call level looping at worst, but the GPU can perform view instancing more efficiently in certain circumstances which are architecture-dependent.

### `D3D12_VIEW_INSTANCING_TIER_3:3`

View instancing is supported and instancing begins with the first shader stage that references SV_ViewID or with rasterization if no shader stage references SV_ViewID. This means that redundant work is eliminated across view instances when it's not dependent on SV_ViewID. Before rasterization, work that doesn't directly depend on SV_ViewID is shared across all views; only work that depends on SV_ViewID is repeated for each view.

**Note** If a hull shader produces tessellation factors that are dependent on SV_ViewID, then tessellation and all subsequent work must be repeated per-view. Similarly, if the amount of geometry produced by the geometry shader depends on SV_ViewID, then the geometry shader must be repeated per-view before proceeding to rasterization.

View instance masking only effects whether work that directly depends on SV_ViewID is performed, not the entire loop iteration (per-view). If the view instance mask is non-0, some work that depends on SV_ViewID might still be performed on masked-off pixels but will have no externally-visible effect; for example, no UAV writes are performed and clipping/rasterization is not invoked. If the view instance mask is 0 no work is performed, including work that's not dependent on SV_ViewID.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)