# PMGM_PRUNE_ALERT_CALLBACK callback function

## Description

The
**PMGM_PRUNE_ALERT_CALLBACK** callback is a call into a routing protocol to notify the protocol that receivers are no longer present on interfaces owned by other routing protocols.

## Parameters

### `dwSourceAddr` [in]

Specifies the source address from which to stop receiving multicast data. Zero indicates to stop receiving data from all sources (a wildcard receiver for a group); otherwise, the value of *dwSourceAddr* is the IP address of the source or source network.

To specify a range of source addresses, the multicast group manager specifies the source network using *dwSourceAddr*, and specifies a subnet mask using *dwSourceMask*.

### `dwSourceMask` [in]

Specifies the subnet mask that corresponds to *dwSourceAddr*. The *dwSourceAddr* and *dwSourceMask* parameters are used together to define a range of sources from which to stop receiving receive multicast data.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwSourceAddr* (a wildcard receiver).

### `dwGroupAddr` [in]

Specifies the multicast group for which to stop receiving data. Zero indicates to stop receiving data for all groups (a wildcard receiver); otherwise, the value of *dwGroupAddr* is the IP address of the group.

To specify a range of group addresses, the multicast group manager specifies the group address using *dwGroupAddr*, and specifies a subnet mask using *dwGroupMask*.

### `dwGroupMask` [in]

Specifies the subnet mask that corresponds to *dwGroupAddr*. The *dwGroupAddr* and *dwGroupMask* parameters are used together to define a range of multicast groups.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwGroupAddr* (a wildcard receiver).

### `dwIfIndex` [in]

Specifies the interface on which to stop receiving multicast data.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

### `bMemberDelete` [in]

Specifies whether the callback was invoked because the
[MgmAddGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmaddgroupmembershipentry) was called by a client (the multicast group manager sets this parameter to **TRUE**), or because an MFE was created or updated (the multicast group manager sets this parameter to **FALSE**).

### `pdwTimeout` [in, out]

On input, *pdwTimeout* points to a **DWORD**-sized memory location.

If *bMemberDelete* is **FALSE**, this parameter can be used to specify how long the corresponding MFE should remain in the multicast forwarding cache. If the client does not specify a value, the default value is 900 seconds.

On output, *pdwTimeout* receives the time-out value, in seconds, for this MFE.

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## Remarks

The multicast group manager sets the *bMemberDelete* parameter to **TRUE** and invokes this callback if a client calls the
[MgmDeleteGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmdeletegroupmembershipentry) function for a (s, g), (*, g), or (*, *) entry (that is, the group membership changes).

The multicast group manager sets the *bMemberDelete* parameter to **FALSE** if the outgoing interface list for an MFE changes. This change typically occurs for a change in membership for the group corresponding to the MFE.

A multicast routing protocol can use the *bMemberDelete* parameter to distinguish between changes to group membership and changes to the MFE.

The action taken by the routing protocol when this callback is received is protocol-specific. The protocol may ignore the callback if the *bMemberDelete* parameter is set to **FALSE**, if the protocol specification indicates that this is the correct behavior.

When
[MgmDeleteGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmdeletegroupmembershipentry) is called, the multicast group manager uses this callback to notify other multicast group manager clients that there are no more receivers for the specified source and group.

The multicast group manager uses the following rules to determine when to invoke this callback for wildcard (*, g) joins:

* If the final interface is being removed for the second-to-last client (that is, when interfaces for only a single client remain), the multicast group manager invokes the
  **PMGM_PRUNE_ALERT_CALLBACK** callback to that remaining client.
* If the final interface is being removed for the last client (that is, when no other interfaces remain), then this callback is invoked for all the other clients that are registered with the multicast group manager.

The multicast group manager uses the following rule to determine when to invoke this callback for source-specific (s, g) joins:

* When a source-specific prune for a group (s, g) is received, the multicast group manager invokes the
  **PMGM_PRUNE_ALERT_CALLBACK** callback only for the client that owns the incoming interface towards the source "s".

This version of the Multicast Group Manager API supports only wildcard sources (*, g) or specific sources (s, g), not a range of sources. The same restriction applies to groups (that is, no group ranges are permitted).

## See also

[PMGM_CREATION_ALERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_creation_alert_callback)