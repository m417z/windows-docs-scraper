# ID3D12DeviceRemovedExtendedData::GetPageFaultAllocationOutput

## Description

Retrieves the Device Removed Extended Data (DRED) page fault data, including matching allocation for both living and recently-deleted runtime objects. The object whose address is passed receives the data.

## Parameters

### `pOutput`

An output parameter that takes the address of a [D3D12_DRED_PAGE_FAULT_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_dred_page_fault_output) object.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10). Returns **DXGI_ERROR_NOT_CURRENTLY_AVAILABLE** if the device is *not* in a removed state. Returns **DXGI_ERROR_UNSUPPORTED** if page fault reporting has not been enabled with [ID3D12DeviceRemovedExtendedDataSettings::SetPageFaultEnablement](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12deviceremovedextendeddatasettings-setpagefaultenablement).

## See also

* [ID3D12DeviceRemovedExtendedData interface](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12deviceremovedextendeddata)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)