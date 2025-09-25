# ID3D11DeviceContext::CopySubresourceRegion

## Description

Copy a region from a source resource to a destination resource.

## Parameters

### `pDstResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the destination resource (see [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)).

### `DstSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Destination subresource index.

### `DstX` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The x-coordinate of the upper left corner of the destination region.

### `DstY` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The y-coordinate of the upper left corner of the destination region. For a 1D subresource, this must be zero.

### `DstZ` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The z-coordinate of the upper left corner of the destination region. For a 1D or 2D subresource, this must be zero.

### `pSrcResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the source resource (see [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)).

### `SrcSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Source subresource index.

### `pSrcBox` [in, optional]

Type: **const [D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)***

A pointer to a 3D box (see [D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)) that defines the source subresource that can be copied. If **NULL**, the entire source subresource is copied. The box must fit within the source resource.

An empty box results in a no-op. A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value, or the front value is greater than or equal to the back value. When the box is empty, **CopySubresourceRegion** doesn't perform a copy operation.

## Remarks

The source box must be within the size of the source resource. The destination offsets, (x, y, and z), allow the source box to be offset when writing into the destination resource; however, the dimensions of the source box and the offsets must be within the size of the resource. If you try and copy outside the destination resource or specify a source box that is larger than the source resource, the behavior of **CopySubresourceRegion** is undefined. If you created a device that supports the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers), the debug output reports an error on this invalid **CopySubresourceRegion** call. Invalid parameters to **CopySubresourceRegion** cause undefined behavior and might result in incorrect rendering, clipping, no copy, or even the removal of the rendering device.

If the resources are buffers, all coordinates are in bytes; if the resources are textures, all coordinates are in texels. [D3D11CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11calcsubresource) is a helper function for calculating subresource indexes.

**CopySubresourceRegion** performs the copy on the GPU (similar to a memcpy by the CPU). As a consequence, the source and destination resources:

* Must be different subresources (although they can be from the same resource).
* Must be the same type.
* Must have compatible DXGI formats (identical or from the same type group). For example, a DXGI_FORMAT_R32G32B32_FLOAT texture can be copied to a DXGI_FORMAT_R32G32B32_UINT texture since both of these formats are in the DXGI_FORMAT_R32G32B32_TYPELESS group. **CopySubresourceRegion** can copy between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).
* May not be currently mapped.

**CopySubresourceRegion** only supports copy; it doesn't support any stretch, color key, or blend. **CopySubresourceRegion** can reinterpret the resource data between a few format types. For more info, see [Format conversion using Direct3D 10.1](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-programming-guide-resources-block-compression#format-conversion-using-direct3d-101).

If your app needs to copy an entire resource, we recommend to use [ID3D11DeviceContext::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource) instead.

**CopySubresourceRegion** is an asynchronous call, which may be added to the command-buffer queue, this attempts to remove pipeline stalls that may occur when copying data. For more information about pipeline stalls, see [performance considerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping).

**Note** **Applies only to feature level 9_x hardware** If you use [ID3D11DeviceContext::UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource) or **CopySubresourceRegion** to copy from a staging resource to a default resource, you can corrupt the destination contents. This occurs if you pass a **NULL** source box and if the source resource has different dimensions from those of the destination resource or if you use destination offsets, (x, y, and z). In this situation, always pass a source box that is the full size of the source resource.

**Note** **Applies only to feature level 9_x hardware** You can't use **CopySubresourceRegion** to copy mipmapped volume textures.

**Note** **Applies only to feature levels 9_x** Subresources created with the D3D11_BIND_DEPTH_STENCIL flag can only be used as a source for **CopySubresourceRegion**.

**Note** If you use **CopySubresourceRegion** with a depth-stencil buffer or a multisampled resource, you must copy the whole subresource. In this situation, you must pass 0 to the *DstX*, *DstY*, and *DstZ* parameters and **NULL** to the *pSrcBox* parameter. In addition, source and destination resources, which are represented by the *pSrcResource* and *pDstResource* parameters, should have identical sample count values.

### Example

The following code snippet copies a box (located at (120,100),(200,220)) from a source texture into a region (10,20),(90,140) in a destination texture.

```
D3D11_BOX sourceRegion;
sourceRegion.left = 120;
sourceRegion.right = 200;
sourceRegion.top = 100;
sourceRegion.bottom = 220;
sourceRegion.front = 0;
sourceRegion.back = 1;

pd3dDeviceContext->CopySubresourceRegion( pDestTexture, 0, 10, 20, 0, pSourceTexture, 0, &sourceRegion );

```

Notice, that for a 2D texture, front and back are set to 0 and 1 respectively.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)

[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)