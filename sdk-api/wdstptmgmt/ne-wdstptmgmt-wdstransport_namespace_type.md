# WDSTRANSPORT_NAMESPACE_TYPE enumeration

## Description

Determines the type of multicast sessions used for transmitting objects covered by this namespace.

## Constants

### `WdsTptNamespaceTypeUnknown:0`

Default value that indicates that the namespace type is not yet known. This could also be the case if a new namespace type was introduced in later server versions and this version of WdsTptMgmt has not been updated to fully recognize and classify it.

### `WdsTptNamespaceTypeAutoCast:1`

Indicates that multicast sessions are to be created automatically by the server based on incoming requests from clients. The server independently decides when to start or end these sessions to optimize performance and reduce network congestion.

### `WdsTptNamespaceTypeScheduledCastManualStart:2`

Indicates that multicast sessions for this namespace are to be scheduled such that they start only when the administrator manually launches them.

### `WdsTptNamespaceTypeScheduledCastAutoStart:3`

Indicates that multicast sessions for this namespace are to be automatically started by the system based on criteria the administrator sets, such as a scheduled start time or minimum number of clients.