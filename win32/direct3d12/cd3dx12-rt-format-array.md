# CD3DX12\_RT\_FORMAT\_ARRAY structure

A helper structure to enable easy initialization of a [**D3D12\_RT\_FORMAT\_ARRAY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rt_format_array) structure.

## Members

**CD3DX12\_RT\_FORMAT\_ARRAY()**

Creates a new, uninitialized, instance of a CD3DX12\_RT\_FORMAT\_ARRAY.

**explicit CD3DX12\_RT\_FORMAT\_ARRAY(const D3D12\_RT\_FORMAT\_ARRAY& o)**

Creates a new instance of a CD3DX12\_RT\_FORMAT\_ARRAY, initialized with values copied from a [**D3D12\_RT\_FORMAT\_ARRAY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rt_format_array) structure.

**explicit CD3DX12\_RT\_FORMAT\_ARRAY(const DXGI\_FORMAT\* pFormats, UINT NumFormats)**

Creates a new instance of a CD3DX12\_RT\_FORMAT\_ARRAY, initialized with the values passed in the parameter list. Contents of the array specified by the *pFormats* parameter are copied into the member array **RTFormats**. The array specified by *pFormats* is assumed to have the same size as **RTFormats**.

**operator const D3D12\_RT\_FORMAT\_ARRAY&() const**

Implicit conversion to a [**D3D12\_RT\_FORMAT\_ARRAY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rt_format_array) structure. Because D3D12\_RT\_FORMAT\_ARRAY is the underlying type of CD3DX12\_DEPTH\_STENCIL\_DESC1, the object is simply returned as a const D3D12\_RT\_FORMAT\_ARRAY reference to itself.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**D3D12\_RT\_FORMAT\_ARRAY**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rt_format_array)

