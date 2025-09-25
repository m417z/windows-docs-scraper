# IUPnPEventSource::Unadvise

## Description

The
**Unadvise** method is invoked by the device host to stop receiving events. The device host passes in the same pointer that it did when it invoked the
[IUPnPEventSource::Advise](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpeventsource-advise) method.

After this method is invoked, the hosted service releases the reference to the event sink that it held.

## Parameters

### `pesSubscriber` [in]

Pointer to the device host's
[IUPnPEventSink](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpeventsink) interface. This must be the same pointer that was passed when
[IUPnPEventSource::Advise](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpeventsource-advise) was invoked.

## Return value

When implementing this method, return S_OK if the method succeeds. Otherwise, return one of the COM error codes defined in WinError.h.

## See also

[IUPnPEventSource](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpeventsource)

[IUPnPEventSource::Advise](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpeventsource-advise)