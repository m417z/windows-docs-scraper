# IWMDMStorage4::FindStorage

## Description

The **FindStorage** method retrieves a storage in the current root storage, based on its persistent unique identifier.

## Parameters

### `findScope` [in]

A [WMDM_FIND_SCOPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-find-scope) enumeration specifying the scope to search.

### `pwszUniqueID` [in]

Persistent unique identifier of the storage to be found. The persistent unique identifier of the storage is described by the **g_wszWMDMPersistentUniqueID** metadata property of the storage.

### `ppStorage` [out]

Pointer to the retrieved storage, if found. The caller must release this interface when done with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method only searches a single memory object (flash card or hard disc) on the device.

A persistent unique identifier identifies content stored on a particular device. It does not represent a content-specific globally unique identifier that remains identical across all devices. Thus, the same content stored in different storages will have different persistent unique identifiers. Similarly, different content may have the same persistent unique identifier when stored on different devices.

The format of the persistent unique identifier depends on the device. The application must have obtained the persistent unique identifier previously by obtaining a storage and querying it for its **WMDM/PersistentUniqueID** property. Use the [GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage4-getspecifiedmetadata) or [GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-getmetadata) methods to request this property.

## See also

[IWMDMDevice3::FindStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-findstorage)

[IWMDMStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-getmetadata)

[IWMDMStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage4)

[IWMDMStorage4::GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage4-getspecifiedmetadata)

[WMDM_FIND_SCOPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-find-scope)