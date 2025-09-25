# IMDSPStorage::GetAttributes

## Description

The **GetAttributes** method retrieves the attributes of this storage object.

## Parameters

### `pdwAttributes` [out]

Pointer to a **DWORD** containing the attributes as defined by in the **IWMDMStorage::GetAttributes** method.

### `pFormat` [out]

Pointer to a **_WAVEFORMATEX** structure that is filled with attribute information about the object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Evaluation of attributes is a crucial step when exposing the contents of the media device. Devices may not support hierarchical storage of data on storage media. The **GetAttributes** method allows the application to infer the support and format of the file system by discovering its structure through object attributes.

For example, the attributes of a top-level **IMDSPStorage** interface indicate a storage medium, and **IMDSPEnumStorage** exposes the contents of the medium. For an .mp3 file, the attributes indicate a file whose type can be determined by further examination of both the attributes and the file name. In a hierarchical medium, the attributes can indicate a directory whose contents can be exposed by **IMDSPStorage::EnumStorage**.

The **_WAVEFORMATEX** parameter is optional. If you pass a valid **_WAVEFORMATEX** pointer to an audio file, **GetAttributes** passes descriptive information back into the structure. However, if the file is not audio, the **_WAVEFORMATEX** parameter is ignored.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage)

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorage2::GetAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage2-getattributes2)

[IMDSPStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-setattributes)

[_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex)