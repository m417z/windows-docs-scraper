# ID3D12Device1::SetResidencyPriority

## Description

This method sets residency priorities of a specified list of objects.

## Parameters

### `NumObjects`

Type: **UINT**

Specifies the number of objects in the *ppObjects* and *pPriorities* arrays.

### `ppObjects` [in]

Type: **ID3D12Pageable***

Specifies an array, of length *NumObjects*, containing references to [ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable) objects.

### `pPriorities` [in]

Type: **const [D3D12_RESIDENCY_PRIORITY](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_residency_priority)***

Specifies an array, of length *NumObjects*, of [D3D12_RESIDENCY_PRIORITY](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_residency_priority) values for the list of objects.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## Remarks

For more information, refer to [Residency](https://learn.microsoft.com/windows/desktop/direct3d12/residency).

## See also

[ID3D12Device1](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device1)