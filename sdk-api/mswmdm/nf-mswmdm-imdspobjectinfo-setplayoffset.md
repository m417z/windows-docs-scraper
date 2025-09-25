# IMDSPObjectInfo::SetPlayOffset

## Description

The **SetPlayOffset** method sets the play offset of the object, in the units pertinent to the object. This specifies the starting point for the next invocation of [IMDSPDeviceControl::Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-play).

## Parameters

### `dwOffset` [in]

**DWORD** containing the play offset to set for the object, in units pertinent to the object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the value passed is greater than the total length of the object minus the current play length, it is clipped to the length of the object minus the play length.

For playable files, the value is specified in milliseconds. The play offset position value does not change when the user starts playing a file on the media device or when an application invokes the [IMDSPDeviceControl::Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-play) method.

For folders or file systems containing playable files, the value indicates the first track that is played when an application invokes the **IMDSPDeviceControl::Play** method.

## See also

[IMDSPObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobjectinfo)

[IMDSPObjectInfo::GetPlayOffset](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobjectinfo-getplayoffset)