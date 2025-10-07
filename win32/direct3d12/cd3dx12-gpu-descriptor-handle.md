# CD3DX12\_GPU\_DESCRIPTOR\_HANDLE structure

A helper structure to enable easy initialization of a [**D3D12\_GPU\_DESCRIPTOR\_HANDLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle) structure.

## Members

**CD3DX12\_GPU\_DESCRIPTOR\_HANDLE()**

Creates a new, uninitialized, instance of a CD3DX12\_GPU\_DESCRIPTOR\_HANDLE.

**explicit CD3DX12\_GPU\_DESCRIPTOR\_HANDLE(const D3D12\_GPU\_DESCRIPTOR\_HANDLE &o)**

Creates a new instance of a CD3DX12\_GPU\_DESCRIPTOR\_HANDLE, initialized with the contents of another [**D3D12\_GPU\_DESCRIPTOR\_HANDLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle) structure.

**CD3DX12\_GPU\_DESCRIPTOR\_HANDLE(CD3DX12\_DEFAULT)**

Creates a new instance of a CD3DX12\_GPU\_DESCRIPTOR\_HANDLE, initialized with default parameters (sets the pointer to zero).

**CD3DX12\_GPU\_DESCRIPTOR\_HANDLE(const D3D12\_GPU\_DESCRIPTOR\_HANDLE &other, INT offsetScaledByIncrementSize)**

Creates a new instance of a CD3DX12\_GPU\_DESCRIPTOR\_HANDLE, initializing the following parameters:

D3D12\_GPU\_DESCRIPTOR\_HANDLE &other

INT offsetScaledByIncrementSize: The number of increments by which to offset.

**CD3DX12\_GPU\_DESCRIPTOR\_HANDLE(const D3D12\_GPU\_DESCRIPTOR\_HANDLE &other, INT offsetInDescriptors, UINT descriptorIncrementSize)**

Creates a new instance of a CD3DX12\_GPU\_DESCRIPTOR\_HANDLE, initializing the following parameters:

D3D12\_GPU\_DESCRIPTOR\_HANDLE &other

INT offsetInDescriptors: The number of descriptors by which to increment.

UINT descriptorIncrementSize: The amount by which to increment for each descriptor, including padding.

**Offset(INT offsetInDescriptors, UINT descriptorIncrementSize)**

Sets the offset based on the specified number of descriptors and how much to increment for each descriptor. Uses the following parameters:

INT offsetInDescriptors: The number of descriptors by which to increment.

UINT descriptorIncrementSize: The amount by which to increment for each descriptor, including padding.

**Offset(INT offsetScaledByIncrementSize)**

Sets the offset based on the specified number of increments. Uses the following parameters:

INT offsetScaledByIncrementSize: The number of increments by which to offset.

**inline operator==( \_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE& other) const**

Tests for equality between the current CD3DX12\_GPU\_DESCRIPTOR\_HANDLE and the specified D3D12\_GPU\_DESCRIPTOR\_HANDLE or CD3DX12\_GPU\_DESCRIPTOR\_HANDLE.

**inline operator!=( \_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE& other) const**

Tests for inequality between the current CD3DX12\_GPU\_DESCRIPTOR\_HANDLE and the specified D3D12\_GPU\_DESCRIPTOR\_HANDLE or CD3DX12\_GPU\_DESCRIPTOR\_HANDLE.

**operator=(const D3D12\_GPU\_DESCRIPTOR\_HANDLE &other)**

Sets the current CD3DX12\_GPU\_DESCRIPTOR\_HANDLE to the same values as the specified D3D12\_GPU\_DESCRIPTOR\_HANDLE or CD3DX12\_GPU\_DESCRIPTOR\_HANDLE.

**inline InitOffsetted(\_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base, INT offsetScaledByIncrementSize)**

Initializes a [**D3D12\_GPU\_DESCRIPTOR\_HANDLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle) structure with the specified number of items. Uses the following parameters:

\_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base: The base address from which to offset.

INT offsetScaledByIncrementSize: The number of increments by which to offset.

**inline InitOffsetted(\_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base, INT offsetInDescriptors, UINT descriptorIncrementSize)**

Initializes a [**D3D12\_GPU\_DESCRIPTOR\_HANDLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle) structure with an offset, using the specified number of descriptors of the given size. Uses the following parameters:

\_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base: The base address from which to offset.

INT offsetInDescriptors: The number of descriptors by which to offset.

UINT descriptorIncrementSize: The amount by which to increment for each descriptor, including padding.

**static inline InitOffsetted(\_Out\_ D3D12\_GPU\_DESCRIPTOR\_HANDLE &handle, \_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base, INT offsetScaledByIncrementSize)**

Initializes a [**D3D12\_GPU\_DESCRIPTOR\_HANDLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle) structure with an offset, using the specified number of descriptors of the given size. Uses the following parameters:

\_Out\_ D3D12\_GPU\_DESCRIPTOR\_HANDLE &handle: Outputs the resulting D3D12\_GPU\_DESCRIPTOR\_HANDLE.

\_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base: The base address from which to offset.

INT offsetScaledByIncrementSize: The number of increments by which to offset.

**static inline InitOffsetted(\_Out\_ D3D12\_GPU\_DESCRIPTOR\_HANDLE &handle, \_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base, INT offsetInDescriptors, UINT descriptorIncrementSize)**

Initializes a [**D3D12\_GPU\_DESCRIPTOR\_HANDLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle) structure with an offset, using the specified number of descriptors of the given size. Uses the following parameters:

\_Out\_ D3D12\_GPU\_DESCRIPTOR\_HANDLE &handle: Outputs the resulting D3D12\_GPU\_DESCRIPTOR\_HANDLE.

\_In\_ const D3D12\_GPU\_DESCRIPTOR\_HANDLE &base: The base address from which to offset.

INT offsetInDescriptors: The number of descriptors by which to offset.

UINT descriptorIncrementSize: The amount by which to increment for each descriptor, including padding.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_GPU\_DESCRIPTOR\_HANDLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

