# IWdsTransportMulticastSessionPolicy::put_MultistreamStreamCount

## Description

Receives the maximum number of multicast streams per transmission used by the server. If the server is configured to handle slow clients using the multistream method, the server detects clients that slow transmission below this maximum and moves them to lower-speed streams of the same multicast transmission. The server cannot move legacy clients that do not support the multistream handling option, and in this case, the server disconnects the client or instructs the client to fallback depending upon the [SlowClientFallback](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportmulticastsessionpolicy-get_slowclientfallback) property.

This property can be used to get or set the maximum stream count regardless of which method the server is using to handle slow clients.

This property is read/write.

## Parameters

## See also

[IWdsTransportMulticastSessionPolicy](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportmulticastsessionpolicy)