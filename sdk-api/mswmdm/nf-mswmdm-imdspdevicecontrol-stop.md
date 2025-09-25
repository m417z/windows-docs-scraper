# IMDSPDeviceControl::Stop

## Description

The **Stop** method stops the current stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_BUSY** | The device is busy. |
| **WMDM_E_NOTSUPPORTED** | The stop function is not implemented on this device. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[IWMDMDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevicecontrol)