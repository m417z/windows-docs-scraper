# IUPnPEventSource::Advise

## Description

The
**Advise** method is invoked by the device host to begin receiving events from the hosted service. The device host passes a pointer to its [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. The hosted service must query this **IUnknown** interface for the
[IUPnPEventSink](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpeventsink) interface the service must use to send event notifications.

## Parameters

### `pesSubscriber` [in]

Pointer to the device host's
[IUPnPEventSink](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpeventsink) interface.

## Return value

When implementing this method, return S_OK if the method succeeds. Otherwise, return one of the COM error codes defined in WinError.h.

## See also

[IUPnPEventSource](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpeventsource)

[IUPnPEventSource::Unadvise](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpeventsource-unadvise)