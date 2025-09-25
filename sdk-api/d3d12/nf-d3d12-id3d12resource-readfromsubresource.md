# ID3D12Resource::ReadFromSubresource

## Description

Uses the CPU to copy data from a subresource, enabling the CPU to read the contents of most textures with undefined layouts.

## Parameters

### `pDstData` [out]

Type: **void***

A pointer to the destination data in memory.

### `DstRowPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance from one row of destination data to the next row.

### `DstDepthPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance from one depth slice of destination data to the next.

### `SrcSubresource`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the index of the subresource to read from.

### `pSrcBox` [in, optional]

Type: **const [D3D12_BOX](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box)***

A pointer to a box that defines the portion of the destination subresource to copy the resource data from.
If NULL, the data is read from the destination subresource with no offset.
The dimensions of the destination must fit the destination (see
[D3D12_BOX](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box)).

An empty box results in a no-op.
A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value, or the front value is greater than or equal to the back value.
When the box is empty, this method doesn't perform any operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

See the Remarks section for [WriteToSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-writetosubresource).

## See also

[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)

[Subresources](https://learn.microsoft.com/windows/desktop/direct3d12/subresources)