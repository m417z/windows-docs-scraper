# IMDSPDeviceControl::GetCapabilities

## Description

The **GetCapabilities** method retrieves the capabilities mask for the device with which this control interface is associated. The capabilities describe the methods of the device control that are supported by the media device.

## Parameters

### `pdwCapabilitiesMask` [out]

Pointer to a **DWORD** containing the capabilities of the device. The following flags can be returned in this variable.

| Flag | Description |
| --- | --- |
| MDM_DEVICECAP_CANPLAY | The media device can play MP3 audio. |
| MDM_DEVICECAP_CANSTREAMPLAY | The media device can play streaming audio directly from the host computer. |
| MDM_DEVICECAP_CANRECORD | The media device can record audio. |
| MDM_DEVICECAP_CANSTREAMRECORD | The media device can record streaming audio directly to the host computer. |
| MDM_DEVICECAP_CANPAUSE | The media device can pause during play or record operations. |
| MDM_DEVICECAP_CANRESUME | The media device can resume an operation from a pause command. |
| MDM_DEVICECAP_CANSTOP | The media device can stop playing before the end of a file. |
| MDM_DEVICECAP_CANSEEK | The media device can seek to a position other than the beginning of a file. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pdwCapabilitiesMask* parameter is an invalid or **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[IMDSPDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevicecontrol)