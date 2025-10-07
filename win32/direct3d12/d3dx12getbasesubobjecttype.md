# D3DX12GetBaseSubobjectType function

Returns the subobject type that corresponds to the base class of the passed-in subobject type.

## Parameters

*SubobjectType*

Type: **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**

An enumeration value that specifies the subobject type that you're interested in.

## Return value

Type: **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**

If *SubobjectType* corresponds to a subobject data type that is derived from another subobject data type, the subobject type of the base subobject data type is returned; otherwise, the passed-in subobject type is returned. For example, if **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_DEPTH\_STENCIL1** is passed in, then **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_DEPTH\_STENCIL** is returned.

## Remarks

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

