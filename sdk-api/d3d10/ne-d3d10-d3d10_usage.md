# D3D10_USAGE enumeration

## Description

Identifies expected resource use during rendering. The usage directly reflects whether a resource is accessible by the CPU and/or the GPU.

## Constants

### `D3D10_USAGE_DEFAULT:0`

A resource that requires read and write access by the GPU. This is likely to be the most common usage choice.

### `D3D10_USAGE_IMMUTABLE:1`

A resource that can only be read by the GPU. It cannot be written by the GPU, and cannot be accessed at all by the CPU. This type of resource must be initialized when it is created, since it cannot be changed after creation.

### `D3D10_USAGE_DYNAMIC:2`

A resource that is accessible by both the GPU and the CPU (write only). A dynamic resource is a good choice for a resource that will be updated by the CPU at least once per frame. To write to a dynamic resource on the CPU, use a **Map** method. You can write to a dynamic resource on the GPU using [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource) or [CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copysubresourceregion).

### `D3D10_USAGE_STAGING:3`

A resource that supports data transfer (copy) from the GPU to the CPU.

## Remarks

An application identifies the way a resource is intended to be used (its usage) in a resource description. There are several structures for creating resources including: [D3D10_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture1d_desc), [D3D10_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture2d_desc), [D3D10_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_texture3d_desc), [D3D10_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_buffer_desc), and [D3DX10_IMAGE_LOAD_INFO](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10-image-load-info).

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>In Direct3D 9, you specify the type of memory a resource should be created in at resource creation time (using D3DPOOL). It was an application's job to decide what memory pool would provide the best combination of functionality and performance.<br><br>In Direct3D 10, an application no longer specifies what type of memory (the pool) to create a resource in. Instead, you specify the intended usage of the resource, and let the runtime (in concert with the driver and a memory manager) choose the type of memory that will achieve the best performance. |

### Resource Usage Restrictions

Each usage dictates a tradeoff between functionality and performance. In general, resource accessing is accomplished with the following APIs.

* CPU access is done with [ID3D10Buffer::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10buffer-map), [ID3D10Texture1D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture1d-map), [ID3D10Texture2D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture2d-map), or [ID3D10Texture3D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture3d-map)
* GPU access is done with [CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copysubresourceregion), [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource), or [UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-updatesubresource).

Use the following table to choose the usage that best describes how the resource will need to be accessed by the CPU and/or the GPU. Of course, there will be performance tradeoffs.

| Resource Usage | Default | Dynamic | Immutable | Staging |
| --- | --- | --- | --- | --- |
| GPU-Read | yes | yes¹ | yes | yes1, 2 |
| GPU-Write | yes¹ |  |  | yes1, 2 |
| CPU-Read |  |  |  | yes1, 2 |
| CPU-Write |  | yes |  | yes1, 2 |

* 1 - This is restricted to [CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copysubresourceregion), [CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource), and [UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-updatesubresource).
* 2 - Cannot be a depth-stencil buffer or a multisampled render target.

### Resource Bind Options

To maximize performance, not all resource usage options can be used as input or output resources to the pipeline. This table identifies these limitations.

| Resource Can Be Bound As | Default | Dynamic | Immutable | Staging |
| --- | --- | --- | --- | --- |
| Input to a Stage | yes³ | yes⁴ | yes |  |
| Output from a Stage | yes³ |  |  |  |

* 3 - If bound as an input and an output using different views, each view must use different [subresources](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).
* 4 - The resource can only be created with a single [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types). The resource cannot be a texture array. The resource cannot be a mipmap chain.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)