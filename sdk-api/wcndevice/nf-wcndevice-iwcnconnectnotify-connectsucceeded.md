# IWCNConnectNotify::ConnectSucceeded

## Description

The **IWCNConnectNotify::ConnectSucceeded** callback method that indicates a successful [IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect) operation.

## Return value

...

## Remarks

Notification of success does not implicitly indicate that the device is ready, as some devices reboot in order to apply settings provided during the [IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect) operation.

If the [IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice) interface was used to obtain network settings from a device, then the network profile is immediately ready for use.

## See also

[IWCNConnectNotify](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcnconnectnotify)

[IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect)