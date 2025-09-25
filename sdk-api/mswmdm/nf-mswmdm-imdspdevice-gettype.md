# IMDSPDevice::GetType

## Description

The **GetType** method retrieves device type information.

## Parameters

### `pdwType` [out]

Pointer to a **DWORD** that receives the type attributes of the device. The following table shows the types received.

| Device type | Description |
| --- | --- |
| WMDM_DEVICE_TYPE_PLAYBACK | The media device supports audio playback. |
| WMDM_DEVICE_TYPE_RECORD | The media device supports audio recording. |
| WMDM_DEVICE_TYPE_DECODE | The media device supports audio format decoding. |
| WMDM_DEVICE_TYPE_ENCODE | The media device supports audio format encoding. |
| WMDM_DEVICE_TYPE_STORAGE | The media device has on-board storage for media files. |
| WMDM_DEVICE_TYPE_SDMI | The media device is SDMI compliant. |
| WMDM_DEVICE_TYPE_NONSDMI | The media device is not SDMI compliant. |
| WMDM_DEVICE_TYPE_VIRTUAL | The media device is not a physical device. |
| WMDM_DEVICE_TYPE_NONREENTRANT | The media device must synchronize access to the service provider services. |
| WMDM_DEVICE_TYPE_FILELISTRESYNC | The media device allows the file list to be resynchronized. |
| WMDM_DEVICE_TYPE_VIEW_PREF_METADATAVIEW | The media device prefers metadata views while its storages are enumerated. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)

[IMDSPDevice::GetName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getname)