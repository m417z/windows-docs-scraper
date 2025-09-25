# ID3D10Device::CopySubresourceRegion

## Description

Copy a region from a source resource to a destination resource.

## Parameters

### `pDstResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

A pointer to the destination resource (see [ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)).

### `DstSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) index of the destination.

### `DstX` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The x coordinate of the upper left corner of the destination region.

### `DstY` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The y coordinate of the upper left corner of the destination region.

### `DstZ` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The z coordinate of the upper left corner of the destination region. For a 1D or 2D subresource, this must be zero.

### `pSrcResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

A pointer to the source resource (see [ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)).

### `SrcSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) index of the source.

### `pSrcBox` [in]

Type: **const [D3D10_BOX](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_box)***

A 3D box (see [D3D10_BOX](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_box)) that defines the source subresource that can be copied. If **NULL**, the entire source subresource is copied. The box must fit within the source resource.

An empty box results in a no-op. A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value, or the front value is greater than or equal to the back value. When the box is empty, **CopySubresourceRegion** doesn't perform a copy operation.

## Remarks

The source box must be within the size of the source resource. The destination location is an absolute value (not a relative value). The destination location can be offset from the source location; however, the size of the region to copy (including the destination location) must fit in the destination resource.

If the resources are buffers, all coordinates are in bytes; if the resources are textures, all coordinates are in texels.

[D3D10CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-d3d10calcsubresource) is a helper function for calculating subresource indexes.

**CopySubresourceRegion** performs the copy on the GPU (similar to a memcpy by the CPU). As a consequence, the source and destination resources must meet the following criteria:

* Must be different subresources (although they can be from the same resource).
* Must be the same [type](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).
* Must have compatible [formats](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) (the formats must either be identical or be from the same type group). For example, a DXGI_FORMAT_R32G32B32_FLOAT texture can be copied to a DXGI_FORMAT_R32G32B32_UINT texture because both of these formats are in the DXGI_FORMAT_R32G32B32_TYPELESS group. Beginning with Direct3D 10.1, **CopySubresourceRegion** can copy between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).
* May not be currently [mapped](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping).

**CopySubresourceRegion** supports only copy; it does not support any stretch, color key, blend, or format conversions. Beginning with Direct3D 10.1, **CopySubresourceRegion** can reinterpret the resource data between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).

If your app needs to copy an entire resource, we recommend to use [ID3D10Device::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource) instead.

**CopySubresourceRegion** is an asynchronous call that the runtime can add to the command-buffer queue. This asynchronous behaviorattempts to remove pipeline stalls that may occur when copying data. See [performance considerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping) for more details.

|  |
| --- |
| Differences between Direct3D 10 and Direct3D 10.1:<br><br>Direct3D 10 has the following limitations:<br><br>* You cannot use a depth-stencil resource as a destination.<br>* You cannot use an immutable resource as a destination.<br>* You cannot use a multisampled texture as either a source or a destination<br><br>Direct3D 10.1 has added support for the following features:<br><br>* You can use a depth-stencil buffer as a source or a destination.<br>* You can use multisampled resources as source and destination only if both source and destination have identical multisampled count and quality. If source and destination differ in multisampled count and quality or if the source is multisampled and the destination is not multisampled (or vice versa), the call to **ID3D10Device::CopySubresourceRegion** fails.<br>* You can copy between uncompressed and compressed resources. During copy, the format conversions that are specified in [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression) are supported automatically. The uncompressed resource must be at least prestructured, and typed. You must also account for the difference between the virtual and the physical size of the mipmaps levels. |

**Note** If you use **CopySubresourceRegion** with a depth-stencil buffer or a multisampled resource, you must copy the whole subresource. You must also pass 0 to the *DstX*, *DstY*, and *DstZ* parameters and **NULL** to the *pSrcBox* parameter. In addition, source and destination resources, which are represented by the *pSrcResource* and *pDstResource* parameters respectively, must have identical sample count values.

### Example

The following code snippet copies a box (located at (120,100),(200,220)) from a source texture into a region (130,120),(210,240) in a destination texture.

```

D3D10_BOX sourceRegion;
sourceRegion.left = 120;
sourceRegion.right = 200;
sourceRegion.top = 100;
sourceRegion.bottom = 220;
sourceRegion.front = 0;
sourceRegion.back = 1;

pd3dDevice->CopySubresourceRegion( pDestTexture, 0, 130, 120, 0, pSourceTexture, 0, &sourceRegion );

```

Notice that, for a 2D texture, front and back are always set to 0 and 1 respectively.

## See also

[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)

[ID3D10Resource Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)