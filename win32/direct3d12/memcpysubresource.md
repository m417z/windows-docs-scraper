# MemcpySubresource function

Copies a subresource row by row.

## Parameters

*pDest* \[in\]

Type: **const [**D3D12\_MEMCPY\_DEST**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_memcpy_dest)\***

A pointer to a [**D3D12\_MEMCPY\_DEST**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_memcpy_dest) structure that describes the destination of the memory copy operation.

*pSrc* \[in\]

Type: **const [**D3D12\_SUBRESOURCE\_DATA**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_data)\***

A pointer to a [**D3D12\_SUBRESOURCE\_DATA**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_data) structure that describes the source of the memory copy operation.

*RowSizeInBytes*

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of each row.

*NumRows*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of rows.

*NumSlices*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of slices.

## Return value

This function does not return a value.

## Remarks

Also consider the following methods:

- [**ID3D12Resource::WriteToSubresource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-writetosubresource)
- [**ID3D12Resource::ReadFromSubresource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-readfromsubresource)
- [**ID3D12GraphicsCommandList::CopyResource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copyresource)

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

[Subresources](https://learn.microsoft.com/windows/win32/direct3d12/subresources)

