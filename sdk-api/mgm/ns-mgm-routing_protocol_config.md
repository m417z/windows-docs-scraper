# ROUTING_PROTOCOL_CONFIG structure

## Description

The
**ROUTING_PROTOCOL_CONFIG** structure describes the routing protocol configuration information that is passed to the multicast group manager when a protocol registers with the multicast group manager.

## Members

### `dwCallbackFlags`

Reserved for future use.

### `pfnRpfCallback`

Callback into a routing protocol to perform an RPF check.

### `pfnCreationAlertCallback`

Callback into a routing protocol to determine the subset of interfaces owned by the routing protocol on which a multicast packet from a new source or to a new group should be forwarded.

### `pfnPruneAlertCallback`

Callback into a routing protocol to notify the protocol that receivers for the specified source and group are no longer present on an interface owned by other routing protocols.

### `pfnJoinAlertCallback`

Callback into a routing protocol to notify the protocol that new receivers for the specified source and group are present on an interface owned by another routing protocol.

### `pfnWrongIfCallback`

Callback into a routing protocol to notify the protocol that a packet has been received from the specified source and for the specified group on the wrong interface.

### `pfnLocalJoinCallback`

Callback into a routing protocol to notify the protocol that IGMP has detected new receivers for a group on an interface.

### `pfnLocalLeaveCallback`

Callback into a routing protocol to notify the protocol that IGMP has detected that there are no more receivers for a group on an interface.

### `pfnDisableIgmpCallback`

Callback into IGMP to notify IGMP that a protocol is taking or releasing ownership of an interface on which IGMP is enabled.

### `pfnEnableIgmpCallback`

Callback into IGMP to notify IGMP that a protocol has finished taking or releasing ownership of an interface on which IGMP is enabled.

## See also

[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol)