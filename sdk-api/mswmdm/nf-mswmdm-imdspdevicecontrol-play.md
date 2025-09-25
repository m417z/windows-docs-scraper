# IMDSPDeviceControl::Play

## Description

The **Play** method begins playing at the current seek position. If the [Seek](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-seek) method has not been called, then playing begins at the beginning of the first file, and the play length is not defined.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_BUSY** | The device is busy. |
| **WMDM_E_NOTSUPPORTED** | The play function is not implemented on this device. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method is used to invoke both device playback (playback of an audio track on a storage medium of the media device) and streaming audio playback (streaming audio data from the user's computer to the media device, where it is played). The **Seek** method determines the form of playback that occurs.

Some devices do not support either device playback or streaming audio playback. Before attempting to start playback of a particular type, the [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-getcapabilities) method must be called. If unsupported playback is attempted, this method returns WMDM_E_NOTSUPPORTED.

To determine whether an audio format can be played by the media device before invoking the play operation, you can call the [IMDSPDevice::GetFormatSupport](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getformatsupport) method.

## See also

[IMDSPDevice::GetFormatSupport](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getformatsupport)

[IMDSPDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevicecontrol)

[IMDSPDeviceControl::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-getcapabilities)

[IMDSPDeviceControl::Seek](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-seek)