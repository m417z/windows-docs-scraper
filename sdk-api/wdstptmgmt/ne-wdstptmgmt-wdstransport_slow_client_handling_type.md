# WDSTRANSPORT_SLOW_CLIENT_HANDLING_TYPE enumeration

## Description

Specifies the type of automatic actions a WDS transport server, running on Windows Server 2008 R2, should use to handle a client computer that is slowing the multicast transmission.

## Constants

### `WdsTptSlowClientHandlingUnknown:0`

Default value that indicates the automatic action used to handle slow client computers is not known.

### `WdsTptSlowClientHandlingNone:1`

Indicates that the server takes no action on any clients that are slowing the multicast transmission.

### `WdsTptSlowClientHandlingAutoDisconnect:2`

Indicates that the server detects clients that are slowing the multicast transmission below a configured threshold. Depending on a configurable setting, the server disconnects the slow clients from the multicast transmission or instructs the slow clients to fallback to an alternate mechanism for retrieving data. For example, a client disconnected from a multicast session can try using unicast instead.

### `WdsTptSlowClientHandlingMultistream:3`

Indicates that the server detects clients that are slowing the multicast transmission below a specified percentage of available bandwidth. The server moves the slow clients to lower-speed streams of the same multicast transmission. The server cannot move legacy clients that do not support the multistream handling option, and in this case, the server disconnects the client or instructs the client to fallback depending upon the [SlowClientFallback](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportmulticastsessionpolicy-get_slowclientfallback) property.