# ID3D12GraphicsCommandList::SetComputeRoot32BitConstants

## Description

Sets a group of constants in the compute root signature.

## Parameters

### `RootParameterIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The slot number for binding.

### `Num32BitValuesToSet` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of constants to set in the root signature.

### `pSrcData` [in]

Type: **const void***

The source data for the group of constants to set.

### `DestOffsetIn32BitValues` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset, in 32-bit values, to set the first constant of the group in the root signature.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)