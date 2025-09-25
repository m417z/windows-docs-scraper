# IMDSPDeviceControl::GetDCStatus

## Description

The **GetDCStatus** method retrieves the control status of the device.

## Parameters

### `pdwStatus` [out]

Pointer to a **DWORD** that contains the control status of the device. The control status value contains one or more of the following flags.

| Flag | Description |
| --- | --- |
| WMDM_STATUS_READY | Windows Media Device Manager and its subcomponents are in a ready state. |
| WMDM_STATUS_BUSY | An operation is currently being performed. Evaluate the other status values to determine which operation it is. |
| WMDM_STATUS_DEVICECONTROL_PLAYING | The device is currently playing. |
| WMDM_STATUS_DEVICECONTROL_RECORDING | The device is currently recording. |
| WMDM_STATUS_DEVICECONTROL_PAUSED | The device is currently paused. |
| WMDM_STATUS_DEVICECONTROL_REMOTE | The play or record operation of the device is being remotely controlled by the application. |
| WMDM_STATUS_DEVICECONTROL_STREAM | The play or record method is streaming data to or from the media device. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pdwStatus* parameter is an invalid or **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This call returns status values specific to the device control operations of this interface. The control status can provide information about the state of control-related activities of the device, such as playing, recording, and so on. However, it cannot provide information about the global status of the device, such as whether the device is downloading data or being accessed for some other reason. If the device is busy for any reason other than device control, you receive a busy code and must call the **GetStatus** method of the associated **IMDSPDevice** interface for more detailed information.

You must not attempt to call the [Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-play), [Record](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-record), [Pause](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-pause), [Resume](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-resume), or [Stop](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-stop) methods of this interface if the status value WMDM_STATUS_BUSY is returned and the status value does not contain any other values from the table of status values.

## See also

[IMDSPDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevicecontrol)