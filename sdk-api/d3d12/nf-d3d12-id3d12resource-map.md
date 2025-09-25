# ID3D12Resource::Map

## Description

Gets a CPU pointer to the specified subresource in the resource, but may not disclose the pointer value to applications. **Map** also invalidates the CPU cache, when necessary, so that CPU reads to this address reflect any modifications made by the GPU.

## Parameters

### `Subresource`

Type: **UINT**

Specifies the index number of the subresource.

### `pReadRange` [in, optional]

Type: **const [D3D12_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range)***

A pointer to a [D3D12_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_range) structure that describes the range of memory to access.

This indicates the region the CPU might read, and the coordinates are subresource-relative. A null pointer indicates the entire subresource might be read by the CPU. It is valid to specify the CPU won't read any data by passing a range where **End** is less than or equal to **Begin**.

### `ppData` [out, optional]

Type: ****void******

A pointer to a memory block that receives a pointer to the resource data.

A null pointer is valid and is useful to cache a CPU virtual address range for methods like [WriteToSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-writetosubresource). When *ppData* is not NULL, the pointer returned is never offset by any values in *pReadRange*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

**Map** and [Unmap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-unmap) can be called by multiple threads safely. Nested **Map** calls are supported and are ref-counted. The first call to **Map** allocates a CPU virtual address range for the resource. The last call to **Unmap** deallocates the CPU virtual address range. The CPU virtual address is commonly returned to the application; but manipulating the contents of textures with unknown layouts precludes disclosing the CPU virtual address. See [WriteToSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-writetosubresource) for more details. Applications cannot rely on the address being consistent, unless **Map** is persistently nested.

Pointers returned by **Map** are not guaranteed to have all the capabilities of normal pointers, but most applications won't notice a difference in normal usage. For example, pointers with WRITE_COMBINE behavior have weaker CPU memory ordering guarantees than WRITE_BACK behavior. Memory accessible by both CPU and GPU are not guaranteed to share the same atomic memory guarantees that the CPU has, due to PCIe limitations. Use fences for synchronization.

There are two usage model categories for **Map**, simple and advanced. The simple usage models maximize tool performance, so applications are recommended to stick with the simple models until the advanced models are proven to be required by the app.

### Simple Usage Models

Applications should stick to the heap type abstractions of UPLOAD, DEFAULT, and READBACK, in order to support all adapter architectures reasonably well.

Applications should avoid CPU reads from pointers to resources on UPLOAD heaps, even accidently. CPU reads will work, but are prohibitively slow on many common GPU architectures, so consider the following:

* Don't make the CPU read from resources associated with heaps that are D3D12_HEAP_TYPE_UPLOAD or have D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE.
* The memory region to which **pData** points can be allocated with [PAGE_WRITECOMBINE](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants), and your app must honor all restrictions that are associated with such memory.
* Even the following C++ code can read from memory and trigger the performance penalty because the code can expand to the following x86 assembly code.

  C++ code:

  ```
  *((int*)MappedResource.pData) = 0;
  ```

  x86 assembly code:

  ```
  AND DWORD PTR [EAX],0
  ```
* Use the appropriate optimization settings and language constructs to help avoid this performance penalty. For example, you can avoid the xor optimization by using a **volatile** pointer or by optimizing for code speed instead of code size.

Applications are encouraged to leave resources unmapped while the CPU will not modify them, and use tight, accurate ranges at all times. This enables the fastest modes for tools, like [Graphics Debugging](https://learn.microsoft.com/visualstudio/debugger/visual-studio-graphics-diagnostics) and the debug layer. Such tools need to track all CPU modifications to memory that the GPU could read.

### Advanced Usage Models

Resources on CPU-accessible heaps can be persistently mapped, meaning **Map** can be called once, immediately after resource creation. [Unmap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-unmap) never needs to be called, but the address returned from **Map** must no longer be used after the last reference to the resource is released. When using persistent map, the application must ensure the CPU finishes writing data into memory before the GPU executes a command list that reads or writes the memory. In common scenarios, the application merely must write to memory before calling [ExecuteCommandLists](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists); but using a fence to delay command list execution works as well.

All CPU-accessible memory types support persistent mapping usage, where the resource is mapped but then never unmapped, provided the application does not access the pointer after the resource has been disposed.

#### Examples

The [D3D12Bundles](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Resource::Map** as follows:

Copy triangle data to the vertex buffer.

```cpp
// Copy the triangle data to the vertex buffer.
UINT8* pVertexDataBegin;
CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
ThrowIfFailed(m_vertexBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pVertexDataBegin)));
memcpy(pVertexDataBegin, triangleVertices, sizeof(triangleVertices));
m_vertexBuffer->Unmap(0, nullptr);

```

 Create an upload heap for the constant buffers.

```cpp
// Create an upload heap for the constant buffers.
ThrowIfFailed(pDevice->CreateCommittedResource(
    &CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD),
    D3D12_HEAP_FLAG_NONE,
    &CD3DX12_RESOURCE_DESC::Buffer(sizeof(ConstantBuffer) * m_cityRowCount * m_cityColumnCount),
    D3D12_RESOURCE_STATE_GENERIC_READ,
    nullptr,
    IID_PPV_ARGS(&m_cbvUploadHeap)));

// Map the constant buffers. Note that unlike D3D11, the resource
// does not need to be unmapped for use by the GPU. In this sample,
// the resource stays 'permanently' mapped to avoid overhead with
// mapping/unmapping each frame.
CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_pConstantBuffers)));

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)

[Subresources](https://learn.microsoft.com/windows/desktop/direct3d12/subresources)

[Unmap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-unmap)