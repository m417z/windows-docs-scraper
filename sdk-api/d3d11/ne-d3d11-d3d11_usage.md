# D3D11_USAGE enumeration

## Description

Identifies expected resource use during rendering. The usage directly reflects whether a resource is accessible by the CPU and/or the graphics processing unit (GPU).

## Constants

### `D3D11_USAGE_DEFAULT:0`

A resource that requires read and write access by the GPU. This is likely to be the most common usage choice.

### `D3D11_USAGE_IMMUTABLE:1`

A resource that can only be read by the GPU. It cannot be written by the GPU, and cannot be accessed at all by the CPU. This type of resource must be initialized when it is created, since it cannot be changed after creation.

### `D3D11_USAGE_DYNAMIC:2`

A resource that is accessible by both the GPU (read only) and the CPU (write only). A dynamic resource is a good choice for a resource that will be updated by the CPU at least once per frame. To update a dynamic resource, use a **Map** method.

For info about how to use dynamic resources, see [How to: Use dynamic resources](https://learn.microsoft.com/windows/desktop/direct3d11/how-to--use-dynamic-resources).

### `D3D11_USAGE_STAGING:3`

A resource that supports data transfer (copy) from the GPU to the CPU.

## Remarks

An application identifies the way a resource is intended to be used (its usage) in a resource description. There are several structures for creating resources including: [D3D11_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture1d_desc), [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc), [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc), and [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc).

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10/11:<br><br>In Direct3D 9, you specify the type of memory a resource should be created in at resource creation time (using D3DPOOL). It was an application's job to decide what memory pool would provide the best combination of functionality and performance.<br><br>In Direct3D 10/11, an application no longer specifies what type of memory (the pool) to create a resource in. Instead, you specify the intended usage of the resource, and let the runtime (in concert with the driver and a memory manager) choose the type of memory that will achieve the best performance. |

### Resource Usage Restrictions

Each usage dictates a tradeoff between accessibility for the CPU and accessibility for the GPU. In general, higher-performance access for one of these two processors means lower-performance access for the other. At either extreme are the **D3D11_USAGE_DEFAULT** and **D3D11_USAGE_STAGING** usages. **D3D11_USAGE_DEFAULT** restricts access almost entirely to the GPU. **D3D11_USAGE_STAGING** restricts access almost entirely to the CPU and allows only a data transfer (copy) of a resource between the GPU and the CPU. You can perform these copy operations via the [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion) and [ID3D11DeviceContext::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource) methods. You can also use these copy methods to copy data between two resources of the same usage. You can also use the [ID3D11DeviceContext::UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource) method to copy memory directly from a CPU-supplied pointer to any resource, most usefully a resource with **D3D11_USAGE_DEFAULT**.

**D3D11_USAGE_DYNAMIC** usage is a special case that optimizes the flow of data from CPU to GPU when the CPU generates that data on-the-fly and sends that data with high frequency. **D3D11_USAGE_DYNAMIC** is typically used on resources with vertex data and on constant buffers. Use the [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) and [ID3D11DeviceContext::Unmap](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-unmap) methods to write data to these resources. To achieve the highest performance for data consumed serially, like vertex data, use the **D3D11_MAP_WRITE_NO_OVERWRITE** and **D3D11_MAP_WRITE_DISCARD** sequence. For more info about this sequence, see [Common Usage of D3D11_MAP_WRITE_DISCARD with D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map).

**D3D11_USAGE_IMMUTABLE** usage is another special case that causes the GPU to generate data just once when you create a resource. **D3D11_USAGE_IMMUTABLE** is well-suited to data such as textures because such data is typically read into memory from some file format. Therefore, when you create a texture with **D3D11_USAGE_IMMUTABLE**, the GPU directly reads that texture into memory.

Use the following table to choose the usage that best describes how the resource will need to be accessed by the CPU and/or the GPU. Of course, there will be performance tradeoffs.

| Resource Usage | Default | Dynamic | Immutable | Staging |
| --- | --- | --- | --- | --- |
| GPU-Read | yes | yes | yes | yes¹ |
| GPU-Write | yes |  |  | yes¹ |
| CPU-Read |  |  |  | yes¹ |
| CPU-Write |  | yes |  | yes¹ |

1 - GPU read or write of a resource with the **D3D11_USAGE_STAGING** usage is restricted to copy operations. You use [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion) and [ID3D11DeviceContext::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource) for these copy operations. Also, because depth-stencil formats and multisample layouts are implementation details of a particular GPU design, the operating system can’t expose these formats and layouts to the CPU in general. Therefore, staging resources can't be a depth-stencil buffer or a multisampled render target.

**Note** You can technically use [ID3D11DeviceContext::UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource) to copy to a resource with any usage except **D3D11_USAGE_IMMUTABLE**. However, we recommend to use [ID3D11DeviceContext::UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource) to update only a resource with **D3D11_USAGE_DEFAULT**. We recommend to use [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) and [ID3D11DeviceContext::Unmap](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-unmap) to update resources with **D3D11_USAGE_DYNAMIC** because that is the specific purpose of **D3D11_USAGE_DYNAMIC** resources, and is therefore the most optimized path.

**Note** **D3D11_USAGE_DYNAMIC** resources consume specific hardware capabilities. Therefore, use them sparingly. The display driver typically allocates memory for **D3D11_USAGE_DYNAMIC** resources with a caching algorithm that favors CPU writes and hinders CPU reads. Furthermore, the memory behind **D3D11_USAGE_DYNAMIC** resources might not even be the same for successive calls to [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map). Therefore, do not expect high performance or even consistent CPU reads from **D3D11_USAGE_DYNAMIC** resources.

**Note** [ID3D11DeviceContext::CopyStructureCount](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copystructurecount) is a special case of GPU-to-CPU copy. Use **ID3D11DeviceContext::CopyStructureCount** only with unordered access views (UAVs) of buffers.

### Resource Bind Options

To maximize performance, not all resource usage options can be used as input or output resources to the pipeline. This table identifies these limitations.

| Resource Can Be Bound As | Default | Dynamic | Immutable | Staging |
| --- | --- | --- | --- | --- |
| Input to a Stage | yes² | yes³ | yes |  |
| Output from a Stage | yes² |  |  |  |

* 2 - If bound as an input and an output using different views, each view must use different subresources.
* 3 - The resource can only be created with a single subresource. The resource cannot be a texture array. The resource cannot be a mipmap chain.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)