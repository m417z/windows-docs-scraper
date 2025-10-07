# D3D12DecomposeSubresource function

Outputs the mip slice, array slice, and plane slice that correspond to the specified subresource index.

## Parameters

*Subresource*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the subresource.

*MipLevels*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels in the subresource.

*ArraySize*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the array.

*MipSlice* \[out, ref\]

Type: **T**

Outputs the mip slice that corresponds to the given subresource index.

*ArraySlice* \[out, ref\]

Type: **U**

Outputs the array slice that corresponds to the given subresource index.

*PlaneSlice* \[out, ref\]

Type: **V**

Outputs the plane slice that corresponds to the given subresource index.

## Return value

This method does not return a value.

## Remarks

This function determines which mip slice, array slice, and plane slice correspond to a given subresource index. This is a useful utility, though it is C++ specific.

This function is declared as follows, with C++ templatized parameters for types **T**, **U**, and **V**:

```c++
template <typename T, typename U, typename V>
inline void D3D12DecomposeSubresource( UINT Subresource, UINT MipLevels, UINT ArraySize, _Out_ T& MipSlice, _Out_ U& ArraySlice, _Out_ V& PlaneSlice )
{
    MipSlice = static_cast<T>(Subresource % MipLevels);
    ArraySlice = static_cast<U>((Subresource / MipLevels) % ArraySize);
    PlaneSlice = static_cast<V>(Subresource / (MipLevels * ArraySize));
}
```

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

[Subresources](https://learn.microsoft.com/windows/win32/direct3d12/subresources)