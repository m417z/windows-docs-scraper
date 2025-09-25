# IDMLDevice::CreateBindingTable

## Description

Creates a binding table, which is an object that can be used to bind resources (such as tensors) to the pipeline.

The binding table wraps a range of an application-managed descriptor heap using the provided descriptor handles
and count. Binding tables are used by DirectML to manage the binding of resources by writing descriptors into
the descriptor heap at the offset specified by the **CPUDescriptorHandle**, and binding those descriptors to the
pipeline using the descriptors at the offset specified by the **GPUDescriptorHandle**. The order in which
DirectML writes descriptors into the heap is unspecified, so your application must take care not to overwrite the
descriptors wrapped by the binding table.

The supplied CPU and GPU descriptor handles may come from different heaps, however it is then your
application's responsibility to ensure that the entire descriptor range referred to by the CPU descriptor
handle is copied into the range referred to by the GPU descriptor handle prior to execution using this binding
table.

The descriptor heap from which the handles are supplied must have type [D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type).
Additionally, the heap referred to by the **GPUDescriptorHandle** must be a shader-visible descriptor heap.

You must not delete the heap referred to by the GPU descriptor handle until all work referencing it has
completed execution on the GPU. You may, however, reset or release the binding table itself as soon as the
dispatch has been recorded into the command list. Similar to the relationship between [ID3D12CommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandlist) and
[ID3D12CommandAllocator](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandallocator), the [IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable) doesn't own the underlying memory referenced by the descriptor
handles. Rather, the [ID3D12DescriptorHeap](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12descriptorheap) does. Therefore, you're permitted to reset or release a DirectML binding table before work using the binding table has completed execution on the GPU.

## Parameters

### `desc` [in, optional]

Type: **const [DML_BINDING_TABLE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_table_desc)***

An optional pointer to a [DML_BINDING_TABLE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_table_desc) containing the binding table parameters. This may be **nullptr**, indicating an empty binding table.

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppv*. This is expected to be the GUID of [IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable).

### `ppv` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the binding table. This is the address of a pointer to an [IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable), representing the binding table created.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)