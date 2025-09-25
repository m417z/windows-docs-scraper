# ID3D12DeviceRemovedExtendedData::GetAutoBreadcrumbsOutput

## Description

Retrieves the Device Removed Extended Data (DRED) auto-breadcrumbs output after device removal.

## Parameters

### `pOutput`

An output parameter that takes the address of a [D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_dred_auto_breadcrumbs_output) object. The object whose address is passed receives the data.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10). Returns **DXGI_ERROR_NOT_CURRENTLY_AVAILABLE** if the device is *not* in a removed state. Returns **DXGI_ERROR_UNSUPPORTED** if auto-breadcrumbs have not been enabled with [ID3D12DeviceRemovedExtendedDataSettings::SetAutoBreadcrumbsEnablement](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12deviceremovedextendeddatasettings-setautobreadcrumbsenablement).

## See also

* [ID3D12DeviceRemovedExtendedData interface](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12deviceremovedextendeddata)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)