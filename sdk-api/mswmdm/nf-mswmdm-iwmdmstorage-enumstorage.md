# IWMDMStorage::EnumStorage

## Description

The **EnumStorage** method retrieves an **IWMDMEnumStorage** interface to enumerate the immediate child storages of the current storage.

## Parameters

### `pEnumStorage` [out]

Pointer to an [IWMDMEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage) interface. The caller must release this interface when done with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **IWMDMEnumStorage** interface that is retrieved will enumerate the immediate children of this object. This method allows an application to navigate the contents of a device recursively.

## See also

[Exploring a Device](https://learn.microsoft.com/windows/desktop/WMDM/exploring-a-device)

[IWMDMDevice::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-enumstorage)

[IWMDMEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)