# D3D12_DISCARD_REGION structure

## Description

Describes details for the discard-resource operation.

## Members

### `NumRects`

The number of rectangles in the array that the **pRects** member specifies.

### `pRects`

An array of **D3D12_RECT** structures for the rectangles in the resource to discard.
If **NULL**, [DiscardResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-discardresource) discards the entire resource.

### `FirstSubresource`

Index of the first subresource in the resource to discard.

### `NumSubresources`

The number of subresources in the resource to discard.

## Remarks

This structure is used by the [ID3D12GraphicsCommandList::DiscardResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-discardresource) method.

If rectangles are supplied in this structure, the resource must have 2D subresources with all specified subresources the same dimension.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)