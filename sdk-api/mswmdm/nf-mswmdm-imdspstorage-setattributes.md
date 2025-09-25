# IMDSPStorage::SetAttributes

## Description

The **SetAttributes** method sets the attributes of a storage object.

## Parameters

### `dwAttributes` [in]

**DWORD** containing the attributes to be set as defined in the **IWMDMStorage::SetAttributes** method.

### `pFormat` [in]

Pointer to a **_WAVEFORMATEX** structure that contains attribute information about the object. This parameter is optional and is ignored if the file is not audio.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Many of the attributes returned by **GetAttributes** (as listed in attribute table for [IWMDMStorage::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes)) cannot be set, so they are not listed in the attribute table for [IWMDMStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-setattributes).

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage)

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorage2::SetAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage2-setattributes2)

[IMDSPStorage::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getattributes)

[_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex)