# IWMDMDevice::EnumStorage

## Description

The **EnumStorage** method retrieves an [IWMDMEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage) interface to enumerate the storages on a device.

Syntax

## Parameters

### `ppEnumStorage` [out]

Pointer to a pointer to an [IWMDMEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage) interface to enumerate the storages on a device. This points to the root storage on the device. The caller is responsible for calling **Release** on the retrieved interface.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[Exploring a Device](https://learn.microsoft.com/windows/desktop/WMDM/exploring-a-device)

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)

[IWMDMEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage)