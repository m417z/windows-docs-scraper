# IWMDMStorage4::SetReferences

## Description

The **SetReferences** method sets the references contained in a storage that has references (such as a playlist or album), overwriting any previously existing references held by the storage.

## Parameters

### `dwRefs` [in]

Count of [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface pointers in *ppIWMDMStorage*. Zero is an acceptable value and clears all references from the storage. The storage itself is not deleted in this case.

### `ppIWMDMStorage` [in]

Pointer to an array of **IWMDMStorage** interface pointers to be referenced by the storage. This order is preserved by the storage. **NULL** is an acceptable value if *dwRefs* is also zero. The caller is responsible for allocating and releasing this array.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is used to set references in objects that are composed of references, such as playlists or albums. If a device does not support metadata, this method will probably not be supported.

Any valid **IWMDMStorage** object can be contained in the *ppIWMDMStorage* array. This includes folders and other storages specifying references themselves (creating, for example, a playlist of playlists). The device itself determines how any particular case of referent object is handled. Windows Media Device Manager does not enforce any rules beyond that of **IWMDMStorage** validity. Consider the case of a playlist containing nested playlist references. On one device, this is disallowed and **SetReferences** fails. On another device, this is allowed; playback simply traverses the entire set of contained references in depth-first order.

The situation may arise where an **IWMDMStorage4** interface pointer corresponds to a storage that no longer exists on the device. WMDM_E_INTERFACEDEAD is returned in this case.

## See also

[Creating a Playlist on the Device](https://learn.microsoft.com/windows/desktop/WMDM/creating-a-playlist-on-the-device)

[IWMDMStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage4)

[IWMDMStorage4::GetReferences](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage4-getreferences)