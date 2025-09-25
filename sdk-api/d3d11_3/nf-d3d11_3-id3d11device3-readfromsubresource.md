# ID3D11Device3::ReadFromSubresource

## Description

Copies data from a
[D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) texture which was mapped using
ID3D11DeviceContext3::[Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) while providing a NULL
[D3D11_MAPPED_SUBRESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_mapped_subresource) parameter.

## Parameters

### `pDstData` [out]

Type: **void***

A pointer to the destination data in memory.

### `DstRowPitch` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of one row of the destination data.

### `DstDepthPitch` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of one depth slice of destination data.

### `pSrcResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the source resource (see
[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)).

### `SrcSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index, that identifies the destination subresource.
For more details, see
[D3D11CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11calcsubresource).

### `pSrcBox` [in, optional]

Type: **const [D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)***

A pointer to a box that defines the portion of the destination subresource to copy the resource data from.
If NULL, the data is read from the destination subresource with no offset.
The dimensions of the destination must fit the destination (see
[D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)).

An empty box results in a no-op.
A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value, or the front value is greater than or equal to the back value.
When the box is empty, this method doesn't perform any operation.

## Remarks

The provided resource must be a
[D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) texture which was mapped for writing by a previous call to
ID3D11DeviceContext3::[Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) while providing a NULL
[D3D11_MAPPED_SUBRESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_mapped_subresource) parameter.

This API is intended for calling at high frequency.
Callers can reduce memory by making iterative calls that update progressive regions of the texture, while provide a small buffer during each call.
It is most efficient to specify large enough regions, though, because this enables D3D to fill whole cache lines in the texture before returning.

For efficiency, ensure the bounds and alignment of the extents within the box are ( 64 / [Bytes per pixel] ) pixels horizontally.
Vertical bounds and alignment should be 2 rows, except when 1-byte-per-pixel formats are used, in which case 4 rows are recommended.
Single depth slices per call are handled efficiently.
It is recommended but not necessary to provide pointers and strides which are 128-byte aligned.

When reading from sub mipmap levels, it is recommended to use larger width and heights than described above.
This is because small mipmap levels may actually be stored within a larger block of memory, with an opaque amount of offsetting which can interfere with alignment to cache lines.

## See also

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)