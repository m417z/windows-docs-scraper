# IWMDMObjectInfo::GetLongestPlayPosition

## Description

The **GetLongestPlayPosition** method retrieves the longest play position of the file. The file must be an audio file on the media device.

## Parameters

### `pdwLongestPos` [out]

Pointer to a **DWORD** specifying the longest play position of the object, in milliseconds.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The object must be an audio data file. For all other object types, this function returns E_INVALIDTYPE.

The last play position changes when either the user starts playing a file on the media device, or when an application invokes the [IWMDMDeviceControl::Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-play) method and that play exceeds the position of the last longest play position.

## See also

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)

[Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-play)