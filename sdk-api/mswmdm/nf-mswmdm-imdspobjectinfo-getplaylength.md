# IMDSPObjectInfo::GetPlayLength

## Description

The **GetPlayLength** method retrieves the play length of the object in units pertinent to the object. This is the remaining length that the object can play, not its total length.

## Parameters

### `pdwLength` [out]

Pointer to a **DWORD** containing the remaining play length of the object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The value of the play length retrieved is either the total length of the object minus the current play position (if the [IMDSPObjectInfo::SetPlayLength](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobjectinfo-setplaylength) method has not been called), or the value set by **IMDSPObjectInfo::SetPlayLength** clipped to be no greater than the total play length of the object minus the current play position.

For playable files, the value returned is specified in milliseconds. The play length information can change either when the user starts playing a file on the media device or when an application invokes the [IMDSPDeviceControl::Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-play) method.

For folders or file systems containing playable files, the value returned is in tracks or numbers of playable files in that folder or in the root of that file system.

## See also

[IMDSPObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobjectinfo)

[IMDSPObjectInfo::SetPlayLength](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobjectinfo-setplaylength)