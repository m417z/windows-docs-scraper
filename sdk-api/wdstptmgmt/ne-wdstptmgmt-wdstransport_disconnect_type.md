# WDSTRANSPORT_DISCONNECT_TYPE enumeration

## Description

Indicates what action a WDS client should take when it is disconnected from the session.

## Constants

### `WdsTptDisconnectUnknown:0`

Default value that indicates that the disconnection type is not known.

### `WdsTptDisconnectFallback:1`

Indicates that the client should leave the session and fallback to an alternate mechanism for retrieving data. For example, a client disconnected from a multicast session can try using unicast instead.

### `WdsTptDisconnectAbort:2`

Indicates that the client should leave the session and abort all attempts to retrieve the data from this server.