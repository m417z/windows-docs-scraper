# GetRequiredIntermediateSize function

Returns the required size of a buffer to be used for data upload.

## Parameters

*pDestinationResource* \[in\]

Type: **[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\***

A pointer to the [**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) interface that represents the destination resource.

*FirstSubresource* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first subresource in the resource. The range of valid values is 0 to D3D12\_REQ\_SUBRESOURCES.

*NumSubresources* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of subresources in the resource. The range of valid values is 0 to (D3D12\_REQ\_SUBRESOURCES - *FirstSubresource*).

## Return value

Type: **[**UINT64**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the buffer, in bytes.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

