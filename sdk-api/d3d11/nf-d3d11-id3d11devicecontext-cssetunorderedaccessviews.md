# ID3D11DeviceContext::CSSetUnorderedAccessViews

## Description

Sets an array of views for an unordered resource.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first element in the zero-based array to begin setting (ranges from 0 to D3D11_1_UAV_SLOT_COUNT - 1). D3D11_1_UAV_SLOT_COUNT is defined as 64.

### `NumUAVs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of views to set (ranges from 0 to D3D11_1_UAV_SLOT_COUNT - *StartSlot*).

### `ppUnorderedAccessViews` [in, optional]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

A pointer to an array of [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) pointers to be set by the method.

### `pUAVInitialCounts` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An array of append and consume buffer offsets. A value of -1 indicates to keep the current offset. Any other values set the hidden counter
for that appendable and consumable UAV. *pUAVInitialCounts* is only relevant for UAVs that were created with either
[D3D11_BUFFER_UAV_FLAG_APPEND](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_buffer_uav_flag) or **D3D11_BUFFER_UAV_FLAG_COUNTER** specified
when the UAV was created; otherwise, the argument is ignored.

## Remarks

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)