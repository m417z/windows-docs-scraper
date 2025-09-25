# IWMDMStorage::GetStorageGlobals

## Description

The **GetStorageGlobals** method retrieves the **IWMDMStorageGlobals** interface of the root storage of this storage.

## Parameters

### `ppStorageGlobals` [out]

Pointer to an [IWMDMStorageGlobals](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals) interface, which provides information about the device such as serial number, capabilities, and so on. The caller must release this interface when finished with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **IWMDMStorageGlobals** interface returned provides methods for accessing global information about the root storage of the current storage. Because this interface exposes global device information, an application only needs to call this method once, on any storage within a single memory container.

## See also

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)