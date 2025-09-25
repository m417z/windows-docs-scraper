# IMDSPStorage2::GetAttributes2

## Description

The **GetAttributes2** method gets attributes of files or storages.

## Parameters

### `pdwAttributes` [out]

Pointer to a **DWORD** containing the base attributes as defined in the **IWMDMStorage::GetAttributes** method.

### `pdwAttributesEx` [out]

Pointer to a **DWORD** containing the extended attributes. Currently no extended attributes are defined.

### `pAudioFormat` [out]

Pointer to a **_WAVEFORMATEX** structure that contains audio format information about the object. This parameter is optional and is ignored if the file is not audio.

### `pVideoFormat` [out]

Pointer to a **_VIDEOINFOHEADER** structure that contains video format information about the object. This parameter is optional and is ignored if the file is not video.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

See remarks for [IWMDMStorage::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes).

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage2)

[IMDSPStorage2::SetAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage2-setattributes2)