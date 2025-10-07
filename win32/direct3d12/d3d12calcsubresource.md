# D3D12CalcSubresource function

Calculates a subresource index for a texture.

## Parameters

*MipSlice*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index for the mipmap level to address; 0 indicates the first, most detailed mipmap level.

*ArraySlice*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index for the array level to address; always use 0 for volume (3D) textures.

*PlaneSlice*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index for the plane level to address.

*MipLevels*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of mipmap levels in the resource.

*ArraySize*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the array.

## Return value

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index which equals MipSlice + (ArraySlice \* MipLevels).

## Remarks

A buffer is an unstructured resource and is therefore defined as containing a single subresource. APIs that take buffers do not need a subresource index. A texture on the other hand is highly structured. Each texture object may contain one or more subresources depending on the size of the array and the number of mipmap levels.

For volume (3D) textures, all slices for a given mipmap level are a single subresource index.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

[Subresources](https://learn.microsoft.com/windows/win32/direct3d12/subresources)

