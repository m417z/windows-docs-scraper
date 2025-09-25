# IWMDMObjectInfo::GetPlayOffset

## Description

The **GetPlayOffset** method retrieves the play offset of the object, in units appropriate to the format. This is the starting point for the next invocation of **Play**.

## Parameters

### `pdwOffset` [out]

Pointer to a **DWORD** specifying the play offset of the object, in units appropriate to the format.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The value retrieved is either zero (if the **SetPlayOffset** method has not been called) or the value set by **SetPlayOffset** clipped to be no greater than the total play length of the object minus one unit.

For playable files, the value returned is specified in milliseconds. The play offset value does not change when the user starts playing a file on the media device or when an application invokes the **IWMDMDeviceControl::Play** method.

For folders or file systems containing playable files, the value returned indicates the first track that is played when an application invokes the **IWMDMDeviceControl::Play** method.

## See also

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)

[Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-play)

[SetPlayOffset](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmobjectinfo-setplayoffset)