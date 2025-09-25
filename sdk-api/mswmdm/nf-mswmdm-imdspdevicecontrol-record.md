# IMDSPDeviceControl::Record

## Description

The **Record** method begins recording from the device's external record input at the current seek position. The [Seek](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-seek) method must be called first.

## Parameters

### `pFormat` [in]

Pointer to a [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure containing the format in which the data must be recorded.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_BUSY** | The device is already performing an operation. |
| **WMDM_E_NOTSUPPORTED** | The record function is not implemented on this device. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method is used to invoke both device recording (recording of an audio track to be stored on the media device) and streaming audio data from the media device to be recorded on the computer. The **Seek** method determines which form of recording occurs.

Some devices do not support either type of recording. The [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-getcapabilities) method must be called before you start recording. If an unsupported type of recording is attempted, this method returns WMDM_E_NOTSUPPORTED.

An argument for the *pFormat* parameter can be supplied to specify an audio data format for recording. To determine the formats supported by the device, see [IMDSPDevice::GetFormatSupport](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getformatsupport). If the *pFormat* parameter is set to **NULL**, the device records audio data in the default format.

When you use device recording, you must enumerate the storage medium contents to find the new object after the record operation is finished.

## See also

[IMDSPDevice::GetFormatSupport](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getformatsupport)

[IMDSPDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevicecontrol)

[IMDSPDeviceControl::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-getcapabilities)

[IMDSPDeviceControl::Seek](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-seek)

[_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex)