# IWCNDevice::GetNetworkProfile

## Description

The **IWCNDevice::GetNetworkProfile** method gets a network profile from the device.

## Parameters

### `cchMaxStringLength` [in]

The allocated size, in characters, of *wszProfile*.

### `wszProfile` [out]

 A string that specifies the XML WLAN network profile type.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The network profile was successfully retrieved. |

## Remarks

 This function can only be called after [IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect) has been called, and the session has completed successfully.

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)

[IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect)