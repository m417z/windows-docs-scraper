# IWMDMObjectInfo::SetPlayOffset

## Description

The **SetPlayOffset** method sets the play offset of the object, in the units appropriate to the format. This specifies the starting point for the next invocation of **Play**.

## Parameters

### `dwOffset` [in]

**DWORD** specifying the play offset, in units appropriate to the format.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the value passed is greater than the total length of the object minus the current play length, it is clipped to the length of the object minus the play length.

For playable files, the value is specified in milliseconds. The play offset position value does not change when the user starts playing a file on the media device or when an application invokes the **IWMDMDeviceControl::Play** method.

For folders or file systems containing playable files, the value indicates the first track that is played when an application invokes the **IWMDMDeviceControl::Play** method.

## See also

[GetPlayOffset](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmobjectinfo-getplayoffset)

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)