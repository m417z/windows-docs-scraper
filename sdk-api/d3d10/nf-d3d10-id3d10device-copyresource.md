# ID3D10Device::CopyResource

## Description

Copy the entire contents of the source resource to the destination resource using the GPU.

## Parameters

### `pDstResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

A pointer to the destination resource (see [ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)).

### `pSrcResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

A pointer to the source resource (see [ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)).

## Remarks

This method is unusual in that it causes the GPU to perform the copy operation (similar to a memcpy by the CPU). As a result, it has a few restrictions designed for improving performance. For instance, the source and destination resources:

* Must be different resources.
* Must be the same [type](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).
* Must have identical dimensions (including width, height, depth, and size as appropriate).
* Must have compatible [formats](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), which means the formats must be identical or at least from the same type group. For example, a DXGI_FORMAT_R32G32B32_FLOAT texture can be copied to a DXGI_FORMAT_R32G32B32_UINT texture since both of these formats are in the DXGI_FORMAT_R32G32B32_TYPELESS group. Beginning with Direct3D 10.1, **CopyResource** can copy between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).
* May not be currently [mapped](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping).

**CopyResource** supports only copy; it does not support any stretch, color key, blend, or format conversions. Beginning with Direct3D 10.1, **CopyResource** can reinterpret the resource data between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).

[Immutable](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage), and [depth-stencil](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) resources cannot be used as a destination. Resources created with [multisampling capability](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) cannot be used as either a source or destination.

The method is an asynchronous call which may be added to the command-buffer queue. This attempts to remove pipeline stalls that may occur when copying data. See [performance considerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping) for more details.

An application that only needs to copy a portion of the data in a resource should use [ID3D10Device::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copysubresourceregion) instead.

|  |
| --- |
| Differences between Direct3D 10 and Direct3D 10.1:<br><br>Direct3D 10.1 enables depth-stencil resources to be used as either a source or destination. Direct3D 10.1 enables multisampled resources to be used as source and destination only if both source and destination have identical multisampled count and quality. If source and destination differ in multisampled count and quality or one of them is multisampled and the other is not multisampled, the call to **ID3D10Device::CopyResource** fails.<br><br>It is possible to copy between prestructured+typed resources and block-compressed textures. See [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression). |

## See also

[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)

[ID3D10Resource Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)