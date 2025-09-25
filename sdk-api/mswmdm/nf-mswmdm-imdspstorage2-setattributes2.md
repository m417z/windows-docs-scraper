# IMDSPStorage2::SetAttributes2

## Description

The **SetAttributes2** method extends **IMDSPStorage::SetAttributes** by enabling you to set audio and video formats and extended attributes of a storage object.

## Parameters

### `dwAttributes` [in]

**DWORD** containing the attributes to be set as defined in the **IWMDMStorage::SetAttributes** method

### `dwAttributesEx` [in]

**DWORD** containing the extended attributes. No extended attributes are currently defined.

### `pAudioFormat` [in]

Pointer to a **_WAVEFORMATEX** structure that contains audio format information about the object. This parameter is optional and is ignored if the file is not audio.

### `pVideoFormat` [in]

Pointer to a **_VIDEOINFOHEADER** structure that contains video format information about the object. This parameter is optional and is ignored if the file is not video.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

See Remarks for [IWMDMStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-setattributes).

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage2)

[IMDSPStorage2::GetAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage2-getattributes2)

[IMDSPStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-setattributes)

[IWMDMStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-setattributes)