# IWMDMStorage2::GetAttributes2

## Description

The **GetAttributes2** method retrieves extended attributes of the storage.

## Parameters

### `pdwAttributes` [out]

Pointer to a **DWORD** specifying one or more attributes defined in the [IWMDMStorage::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes) method, combined with a bitwise **OR**.

### `pdwAttributesEx` [out]

Pointer to a **DWORD** specifying the extended attributes. Currently, no extended attributes are defined.

### `pAudioFormat` [out]

Optional pointer to a [_ WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure that specifies audio information about the object. This parameter is ignored if the file is not audio.

### `pVideoFormat` [out]

Optional pointer to a [_ VIDEOINFOHEADER](https://learn.microsoft.com/windows/desktop/WMDM/-videoinfoheader) structure that specifies video information about the object. This parameter is ignored if the file is not video.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Evaluation of attributes is a crucial step when exposing the contents of the media device. Some devices do not support hierarchical storage of data on storage media. The **GetAttributes2** method is used to infer the support and format of the file system by discovering its structure through object attributes.

## See also

[IWMDMEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage)

[IWMDMStorage2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage2)

[IWMDMStorage2::SetAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage2-setattributes2)

[IWMDMStorage::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-enumstorage)