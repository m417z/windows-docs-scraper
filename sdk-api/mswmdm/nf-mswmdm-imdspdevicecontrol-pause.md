# IMDSPDeviceControl::Pause

## Description

The **Pause** method pauses the current play or record session at the current position within the content.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The device is already paused. |
| **WMDM_E_NOTSUPPORTED** | The pause function is not implemented on this device. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The current play or record session is paused and the current file position is saved. A subsequent call to the **Resume** method restarts the play or record operation at the saved file position.

## See also

[IMDSPDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevicecontrol)