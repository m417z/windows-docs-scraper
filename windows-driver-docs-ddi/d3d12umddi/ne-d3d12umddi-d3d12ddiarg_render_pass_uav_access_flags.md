# D3D12DDIARG_RENDER_PASS_UAV_ACCESS_FLAGS enumeration

## Description

Used to specify what type of UAV (Unordered Access View) access to perform within the Render Pass.

## Constants

### `D3D12DDI_RENDER_PASS_UAV_ACCESS_NO_ACCESS`

Indicates that the Render Pass does not allow UAV access.

### `D3D12DDI_RENDER_PASS_UAV_ACCESS_READ`

Indicates that the Render Pass allows read access.

### `D3D12DDI_RENDER_PASS_UAV_ACCESS_WRITE`

Indicates that the Render Pass allows write access.

## Remarks

UAV bindings via root tables or root descriptors are inherited into Render Passes, and are propagated out of Render Passes.

## See also