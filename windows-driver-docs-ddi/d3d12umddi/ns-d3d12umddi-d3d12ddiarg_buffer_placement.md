## Description

The **D3D12DDIARG_BUFFER_PLACEMENT** structure specifies the GPU-side virtual address that a resource should have.

## Members

### `BaseAddress`

Union whose members are ways to describe the base address for a region of memory.

### `BaseAddress.UMD`

A **D3D12DDIARG_HRESOURCE_PLACEMENT** structure that describes a base address with a UMD handle to an existing resource, and a byte offset within that resource.

## See also

[**D3D12DDIARG_CREATERESOURCE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createresource_0088)