## Description

Retrieves the [Direct3D 12 device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device) being interoperated with. This enables better interoperability with a component that might be handed a Direct3D 11 device, but which wants to leverage Direct3D 12 instead.

## Parameters

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in `ppvDevice`. This is expected to be the GUID of [ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device).

### `ppvDevice`

Type: **[void](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)\*\***

A pointer to a memory block that receives a pointer to the device. This is the address of a pointer to an [ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device), representing the Direct3D 12 device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also

* [ID3D12Device interface](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)