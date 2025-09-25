# IWMDMDeviceControl::Resume

## Description

The **Resume** method resumes the current play or record operation from the file position saved during the call to [Pause](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-pause).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The device is not paused. |
| **WMDM_E_NOTSUPPORTED** | The resume function is not implemented on this device. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[IWMDMDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevicecontrol)

[IWMDMDeviceControl::Pause](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-pause)

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)