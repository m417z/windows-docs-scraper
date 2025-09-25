# ID3D11DeviceContext::CSGetUnorderedAccessViews

## Description

Gets an array of views for an unordered resource.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first element in the zero-based array to return (ranges from 0 to D3D11_1_UAV_SLOT_COUNT - 1).

### `NumUAVs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of views to get (ranges from 0 to D3D11_1_UAV_SLOT_COUNT - StartSlot).

### `ppUnorderedAccessViews` [out, optional]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)****

A pointer to an array of interface pointers (see [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)) to get.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call **IUnknown::Release** on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)