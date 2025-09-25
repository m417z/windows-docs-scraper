# ID3D11DeviceContext::CopyResource

## Description

Copy the entire contents of the source resource to the destination resource using the GPU.

## Parameters

### `pDstResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface that represents the destination resource.

### `pSrcResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface that represents the source resource.

## Remarks

This method is unusual in that it causes the GPU to perform the copy operation (similar to a memcpy by the CPU). As a result, it has a few restrictions designed for improving performance. For instance, the source and destination resources:

* Must be different resources.
* Must be the same type.
* Must have identical dimensions (including width, height, depth, and size as appropriate).
* Must have compatible [DXGI formats](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), which means the formats must be identical or at least from the same type group. For example, a DXGI_FORMAT_R32G32B32_FLOAT texture can be copied to a DXGI_FORMAT_R32G32B32_UINT texture since both of these formats are in the DXGI_FORMAT_R32G32B32_TYPELESS group. [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource) can copy between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).
* Can't be currently mapped.

**CopyResource** only supports copy; it doesn't support any stretch, color key, or blend. [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource) can reinterpret the resource data between a few format types. For more info, see [Format Conversion using Direct3D 10.1](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression).

You can't use an [Immutable](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) resource as a destination. You can use a [depth-stencil](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) resource as either a source or a destination provided that the feature level is D3D_FEATURE_LEVEL_10_1 or greater. For feature levels 9_x, resources created with the D3D11_BIND_DEPTH_STENCIL flag can only be used as a source for [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource). Resources created with multisampling capability (see [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc)) can be used as source and destination only if both source and destination have identical multisampled count and quality. If source and destination differ in multisampled count and quality or if one is multisampled and the other is not multisampled, the call to **ID3D11DeviceContext::CopyResource** fails. Use [ID3D11DeviceContext::ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-resolvesubresource) to resolve a multisampled resource to a resource that is not multisampled.

The method is an asynchronous call, which may be added to the command-buffer queue. This attempts to remove pipeline stalls that may occur when copying data. For more info, see [performance considerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping).

We recommend to use [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion) instead if you only need to copy a portion of the data in a resource.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)

[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)