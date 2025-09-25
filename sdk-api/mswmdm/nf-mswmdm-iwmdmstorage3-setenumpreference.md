# IWMDMStorage3::SetEnumPreference

## Description

The **SetEnumPreference** method sets the preferred view mode for the storage.

## Parameters

### `pMode` [in, out]

Desired mode of the storage enumerator. For more details on the mode, see [WMDM_STORAGE_ENUM_MODE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-storage-enum-mode). If the value of *pMode* is set to ENUM_MODE_USE_DEVICE_PREF, then upon return it is set to ENUM_MODE_RAW or ENUM_MODE_METADATA_VIEWS, based on the device preference.

### `nViews` [in]

Number of view definitions provided.

This parameter is ignored if the value of *pMode* is ENUM_MODE_RAW or if the value of *pMode* is ENUM_MODE_USE_DEVICE_PREF and the device does not prefer metadata views.

If the value of *pMode* is ENUM_MODE_METADATA_VIEWS or if the value of *pMode* is ENUM_MODE_USE_DEVICE_PREF and the device prefers metadata views, this parameter can still be 0. In this case, Windows Media Device Manager uses its default metadata views.

If the value of *nViews* is 0, *ppViews* must be **NULL**. If the value of *nViews* is not 0, *ppViews* must point to an array of [WMDMMetadataView](https://learn.microsoft.com/windows/desktop/WMDM/wmdmmetadataview) structures with *nViews* elements.

### `pViews` [in]

Array of view definitions. The length of the array must be equal to *nViews*.

This parameter is ignored if the value of *pMode* is ENUM_MODE_RAW or if the value of *pMode* is ENUM_MODE_USE_DEVICE_PREF and the device does not prefer metadata views.

If the value of *pMode* is ENUM_MODE_METADATA_VIEWS or if the value of *pMode* is ENUM_MODE_USE_DEVICE_PREF and the device prefers metadata views, this parameter can still be **NULL**. In this case Windows Media Device Manager uses its default metadata views.

The value of this parameter must be **NULL** if the value of *nViews* is 0. If the value of *nViews* is not 0, *ppViews* must point to an array of [WMDMMetadataView](https://learn.microsoft.com/windows/desktop/WMDM/wmdmmetadataview) structures with *nViews* elements.

## Return value

The method returns an **HRESULT**. The following table lists all possible values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the item. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **WMDM_E_NOT_CERTIFIED** | The caller does not have the rights to execute this operation. |
| **WMDM_E_NOTSUPPORTED** | The object does not support this method. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Windows Media Device Manager can present metadata views of the content on the device. It walks through all the content on a top-level storage (such as internal memory or a storage card) and returns a storage enumerator that presents the content organized by the metadata of the content. The definition of a metadata view is provided through a [WMDMMetadataView](https://learn.microsoft.com/windows/desktop/WMDM/wmdmmetadataview) structure.

This behavior is controlled by the *pMode* parameter. If the *pMode* is set to ENUM_MODE_RAW, Windows Media Device Manager returns an enumerator that mirrors the hierarchy of the file system on the storage of the device. If the *pMode* is set to ENUM_MODE_METADATA_VIEWS, Windows Media Device Manager generates metadata views.

Devices indicate their preference by setting the device parameter *UseMetadataViews* at the time the device is installed. For more information about *UseMetadataViews*, see [Device Parameters](https://learn.microsoft.com/windows/desktop/WMDM/device-parameters). If the application will let the device decide on the kind of storage enumerator returned, it should set *pMode* to ENUM_MODE_USE_DEVICE_PREF.

After this method is called, later calls to [IWMDMStorage::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-enumstorage) will behave according to the storage enumeration preference set by this method. This method can be called again to change the behavior of subsequent **IWMDMStorage::EnumStorage** calls.

This method should typically be called on the top-level storage. If this method is called on any of the storages in metadata view, it will return WMDM_E_NOTSUPPORTED.

## See also

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorage::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-enumstorage)

[WMDMMetadataView](https://learn.microsoft.com/windows/desktop/WMDM/wmdmmetadataview)