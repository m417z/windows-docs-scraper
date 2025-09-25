# IWMDMDevice::GetType

## Description

The **GetType** method retrieves the operations supported by the device.

## Parameters

### `pdwType` [out]

Pointer to a **DWORD** specifying the device type attributes. The possible values returned in *pdwType* are defined in the following table. Microsoft recommends setting both WMDM_DEVICE_TYPE_SDMI and WMDM_DEVICE_TYPE_NONSDMI flags.

| Device type | Description |
| --- | --- |
| WMDM_DEVICE_TYPE_PLAYBACK | The media device supports audio playback. |
| WMDM_DEVICE_TYPE_RECORD | The media device supports audio recording. |
| WMDM_DEVICE_TYPE_DECODE | The media device supports audio format decoding. |
| WMDM_DEVICE_TYPE_ENCODE | The media device supports audio format encoding. |
| WMDM_DEVICE_TYPE_STORAGE | The media device has on-board storage for media files. |
| WMDM_DEVICE_TYPE_VIRTUAL | The media device is not a physical device. |
| WMDM_DEVICE_TYPE_SDMI | The media device can accept SDMI-protected content. |
| WMDM_DEVICE_TYPE_NONSDMI | The media device can accept non-SDMI content. |
| WMDM_DEVICE_TYPE_NONREENTRANT | The media device must synchronize access to Windows Media Device Manager services. |
| WMDM_DEVICE_TYPE_FILELISTRESYNC | The media device allows the file list to be resynchronized. |
| WMDM_DEVICE_TYPE_VIEW_PREF_METADATAVIEW | The media device prefers metadata views while its storages are enumerated. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The current Microsoft service providers may not provide reliable information about devices, except WMDM_DEVICE_TYPE_NONSDMI or WMDM_DEVICE_TYPE_SDMI. All devices will be reported as supporting the former; devices that support serial numbers also return the latter.

## See also

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)

[IWMDMDevice::GetName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getname)