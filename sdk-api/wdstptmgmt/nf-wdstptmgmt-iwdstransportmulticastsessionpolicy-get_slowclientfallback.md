# IWdsTransportMulticastSessionPolicy::get_SlowClientFallback

## Description

Receives a value that indicates the fallback policy requested by the server when automatically disconnecting slow clients from a multicast transmission. A value of **VARIANT_FALSE** requests that the client disconnect from the server and discontinue any further attempts to get the content from this server. A value of **VARIANT_TRUE** requests that the client use any alternative method available to the client to get the content, for example unicasting.

This property can be used to get or set the fallback policy regardless of which method the server is using to handle slow clients.

This policy is only used when the server is automatically disconnecting a slow client from a multicast transmission. An administrator manually disconnecting a client, can specify the fallback method.

This property is read/write.

## Parameters

## See also

[IWdsTransportMulticastSessionPolicy](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportmulticastsessionpolicy)