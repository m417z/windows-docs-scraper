# D3D12_BOX structure

## Description

Describes a 3D box.

## Members

### `left`

The x position of the left hand side of the box.

### `top`

The y position of the top of the box.

### `front`

The z position of the front of the box.

### `right`

The x position of the right hand side of the box, plus 1. This means that `right - left` equals the width of the box.

### `bottom`

The y position of the bottom of the box, plus 1. This means that `bottom - top` equals the height of the box.

### `back`

The z position of the back of the box, plus 1. This means that `back - front` equals the depth of the box.

## Remarks

This structure is used by the methods [WriteToSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-writetosubresource), [ReadFromSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-readfromsubresource) and [CopyTextureRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion).

## See also

[CD3DX12_BOX](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-box)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)