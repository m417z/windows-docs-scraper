# UpdateSubresources function

Updates subresources, all the subresource arrays should be populated, typically by calling [**ID3D12Device::GetCopyableFootprints**](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getcopyablefootprints).

## Parameters

*pCmdList* \[in\]

Type: **[**ID3D12GraphicsCommandList**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)\***

The command list, as a pointer to an [**ID3D12GraphicsCommandList**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist).

*pDestinationResource* \[in\]

Type: **[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\***

The destination resource, as a pointer to an [**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource).

*pIntermediate* \[in\]

Type: **[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\***

The intermediate resource, as a pointer to an [**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource).

*FirstSubresource* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first subresource in the resource. The range of valid values is 0 to D3D12\_REQ\_SUBRESOURCES.

*NumSubresources* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of subresources in the resource. The range of valid values is 0 to (D3D12\_REQ\_SUBRESOURCES - *FirstSubresource*).

*RequiredSize*

Type: **[**UINT64**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The required size, in bytes, for the update.

*pLayouts* \[in\]

Type: **const [**D3D12\_PLACED\_SUBRESOURCE\_FOOTPRINT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint)\***

Pointer to an array (of length *NumSubresources*) of pointers to the structures that contains the description and placement of the resource's subresources.

*pNumRows* \[in\]

Type: **const [**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Pointer to an array (of length *NumSubresources*) of UINTS containing the number of rows for each subresource.

*pRowSizesInBytes* \[in\]

Type: **const [**UINT64**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Pointer to an array (of length *NumSubresources*) of UINTS containing the size, in bytes, of each row.

*pSrcData* \[in\]

Type: **const [**D3D12\_SUBRESOURCE\_DATA**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_data)\***

Pointer to an array (of length *NumSubresources*) of pointers to [**D3D12\_SUBRESOURCE\_DATA**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_data) structures containing descriptions of the subresource data used for the update.

## Return value

Type: **[**UINT64**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the buffer.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

[Subresources](https://learn.microsoft.com/windows/win32/direct3d12/subresources)

