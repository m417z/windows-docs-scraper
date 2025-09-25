# IWMDMObjectInfo::SetPlayLength

## Description

The **SetPlayLength** method sets the play length of the object, in units appropriate to the format. This is the maximum length that the object plays regardless of its actual length.

## Parameters

### `dwLength` [in]

**DWORD** specifying the play length, in units appropriate to the format.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the value passed in is greater than the total length of the object, it is clipped to the length of the object minus the object's current play position minus one unit.

For playable files, the value to set is specified in milliseconds. The value is clipped to no more than the total length of the file minus the object's current play offset position. The play position information can change either when the user starts playing a file on the media device or when an application invokes the [IWMDMDeviceControl::Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-play) method.

For folders or file systems containing playable files, the value passed is the number of playable files in that folder or in the root of that file system.

## See also

[GetPlayLength](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmobjectinfo-getplaylength)

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)