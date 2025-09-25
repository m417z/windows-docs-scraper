# D3D12_VIEWPORT structure

## Description

Describes the dimensions of a viewport.

## Members

### `TopLeftX`

X position of the left hand side of the viewport.

### `TopLeftY`

Y position of the top of the viewport.

### `Width`

Width of the viewport.

### `Height`

Height of the viewport.

### `MinDepth`

Minimum depth of the viewport. Ranges between 0 and 1.

### `MaxDepth`

Maximum depth of the viewport. Ranges between 0 and 1.

## Remarks

Pass an array of these structures to the *pViewports* parameter in a call to [ID3D12GraphicsCommandList::RSSetViewports](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-rssetviewports) to set viewports for the display.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)