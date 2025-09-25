# D3D12_RENDER_PASS_FLAGS enumeration

## Description

Specifies the nature of the render pass; for example, whether it is a suspending or a resuming render pass.

## Constants

### `D3D12_RENDER_PASS_FLAG_NONE:0`

Indicates that the render pass has no special requirements.

### `D3D12_RENDER_PASS_FLAG_ALLOW_UAV_WRITES:0x1`

Indicates that writes to unordered access view(s) should be allowed during the render pass.

### `D3D12_RENDER_PASS_FLAG_SUSPENDING_PASS:0x2`

Indicates that this is a suspending render pass.

### `D3D12_RENDER_PASS_FLAG_RESUMING_PASS:0x4`

Indicates that this is a resuming render pass.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)