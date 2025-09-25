# ID3D10Device::GetDeviceRemovedReason

## Description

Get the reason why the device was removed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include:

* DXGI_ERROR_DEVICE_HUNG
* DXGI_ERROR_DEVICE_REMOVED
* DXGI_ERROR_DEVICE_RESET
* DXGI_ERROR_DRIVER_INTERNAL_ERROR
* DXGI_ERROR_INVALID_CALL
* S_OK

For more detail on these return codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)