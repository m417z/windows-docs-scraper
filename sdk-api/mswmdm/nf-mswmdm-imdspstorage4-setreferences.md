# IMDSPStorage4::SetReferences

## Description

The **SetReferences** method sets the references contained in a storage that has references (such as playlist/album), overwriting any previously existing references contained in this storage.

## Parameters

### `dwRefs` [in]

Count of **IMDSPStorage** interface pointers contained in the passed-in array. Zero is an acceptable value and resets the storage to contain zero references. The storage itself is not deleted in this case.

### `ppISPStorage` [in]

Pointer to an array of **IMDSPStorage** interface pointers used to set references in a storage. The ordering of references matches the ordering of the corresponding **IWMDMStorage** interface pointers in this array. **NULL** is an acceptable value if *dwRefs* is also zero.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Any valid **IMDSPStorage** object may be contained in the *ppIMDSPStorage* array. This includes folders and other storages containing references themselves (creating, for example, a playlist of playlists).

Depending upon the level of support in the device (whether it supports playlists or nested playlists), the service provider should handle this method appropriately. If the device does not have the level of supported needed for the passed-in reference array, the service provider should return WMDM_E_NOTSUPPORTED.

If the reference contains a deleted storage, WMDM_E_INTERFACEDEAD should be returned.

The **SetReferences** method follows a wipe-and-load model. The references passed include a complete set and should replace any existing references on the storage object completely.

## See also

[IMDSPStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage4)

[IMDSPStorage4::GetReferences](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage4-getreferences)