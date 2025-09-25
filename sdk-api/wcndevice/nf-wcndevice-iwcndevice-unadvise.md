# IWCNDevice::Unadvise

## Description

The **IWCNDevice::Unadvise** method removes any callback previously set via [IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect).

## Return value

This method does not return a value.

## Remarks

It is not necessary to call **IWCNDevice::Unadvise** unless the application is shutting down and must ensure that no more callbacks are received on its [IWCNConnectNotify](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcnconnectnotify) callback.
Do not call **IWCNDevice::Unadvise** from within an **IWCNConnectNotify** callback, since that will cause a deadlock.
Note that **IWCNDevice::Unadvise** does not cancel the connect operation on the wire.

## See also

[IWCNConnectNotify](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcnconnectnotify)

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)

[IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect)