# IWCNDevice::SetNetworkProfile

## Description

The **IWCNDevice::SetNetworkProfile** method queues an XML WLAN profile to be provisioned to the device. This method may only be called prior to [IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect).

## Parameters

### `pszProfileXml` [in]

The XML WLAN profile XML string.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The attribute was retrieved successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The WLAN profile is not supported for WCN connections. |
| **HRESULT_FROM_WIN32(ERROR_BAD_PROFILE)** | The provided XML profile cannot be read. |

## Remarks

Currently, the **Windows Connect Now API** (WCNAPI) supports the following profile types:

* None (Open or Shared)
* WEP (Open or Shared)
* WPA-PSK (TKIP or AES)
* WPA2-PSK (TKIP or AES)

If the specified WLAN profile has extraneous settings (like IHV settings), these settings will be ignored. In the event a WLAN profile is not compatible with the WCNAPI, an **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** value is returned.

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)