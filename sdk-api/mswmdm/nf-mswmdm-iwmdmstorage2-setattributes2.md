# IWMDMStorage2::SetAttributes2

## Description

The **SetAttributes2** method sets extended attributes of the storage.

## Parameters

### `dwAttributes` [in]

**DWORD** specifying the base attributes defined in the [IWMDMStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-setattributes) method.

### `dwAttributesEx` [in]

**DWORD** specifying extended attributes. Currently, no extended attributes are defined.

### `pFormat` [out]

Optional pointer to a [_ WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure that specifies audio information about the object. This parameter is ignored if the file is not audio.

### `pVideoFormat` [in]

Optional pointer to a [_VIDEOINFOHEADER](https://learn.microsoft.com/windows/desktop/WMDM/-videoinfoheader) structure that specifies video information about the object. This parameter is ignored if the file is not video.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMStorage2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage2)

[IWMDMStorage2::GetAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage2-getattributes2)