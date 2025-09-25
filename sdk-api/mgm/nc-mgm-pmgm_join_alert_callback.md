# PMGM_JOIN_ALERT_CALLBACK callback function

## Description

The
**PMGM_JOIN_ALERT_CALLBACK** callback is a call into a routing protocol to notify the protocol that new receivers are present for one or more groups on interfaces that are owned by other routing protocols. Once a routing protocol receives this callback, it should begin forwarding multicast data for the specified source and group.

## Parameters

### `dwSourceAddr` [in]

Specifies the source address from which the multicast data was received. Zero indicates that data is received from all sources (a wildcard receiver for a group); otherwise, the value of *dwSourceAddr* is the IP address of the source or source network.

To specify a range of source addresses, the multicast group manager specifies the source network using *dwSourceAddr*, and specifies a subnet mask using *dwSourceMask*.

### `dwSourceMask` [in]

Specifies the subnet mask that corresponds to *dwSourceAddr*. The *dwSourceAddr* and *dwSourceMask* parameters are used together to define a range of sources from which to receive multicast data.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwSourceAddr* (a wildcard receiver).

### `dwGroupAddr` [in]

Specifies the multicast group for which the data is destined. Zero indicates that all groups are received (a wildcard receiver); otherwise, the value of *dwGroupAddr* is the IP address of the group.

To specify a range of group addresses, the multicast group manager specifies the group address using *dwGroupAddr*, and specifies a subnet mask using *dwGroupMask*.

### `dwGroupMask` [in]

Specifies the subnet mask that corresponds to *dwGroupAddr*. The *dwGroupAddr* and *dwGroupMask* parameters are used together to define a range of multicast groups.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwGroupAddr* (a wildcard receiver).

### `bMemberUpdate` [in]

Specifies whether the callback was invoked because the
[MgmAddGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmaddgroupmembershipentry) was called by a client (the multicast group manager sets this parameter to **TRUE**), or because an MFE was created or updated (the multicast group manager sets this parameter to **FALSE**).

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## Remarks

The multicast group manager sets the *bMemberUpdate* parameter to **TRUE** and invokes this callback if a client calls the
[MgmAddGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmaddgroupmembershipentry) function for a (s, g), (*, g), or (*, *) entry (that is, the group membership has changed).

The multicast group manager sets the *bMemberUpdate* parameter to **FALSE** if the outgoing interface list for an MFE changes. This change typically occurs for a change in membership for the group corresponding to the MFE.

A multicast routing protocol can use the *bMemberUpdate* parameter to distinguish between changes to group membership and changes to the MFE.

The action taken by the routing protocol when this callback is received is protocol-specific. The protocol may ignore the callback if the *bMemberUpdate* parameter is set to **FALSE**, if the protocol specification indicates that this is the correct behavior.

When
[MgmAddGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmaddgroupmembershipentry) is called, the multicast group manager uses this callback to notify other multicast group manager clients that there are receivers for the specified source and group.

The multicast group manager uses the following rules to determine when to invoke this callback for wildcard (*, g) joins:

* If this is the first client to inform the multicast group manager that there are receivers on an interface for a group, the multicast group manager invokes the
  **PMGM_JOIN_ALERT_CALLBACK** callback to all other registered clients.
* If this is the second client to inform the multicast group manager that there are receivers on an interface for a group, the multicast group manager invokes this callback to the first client to join the group.

The multicast group manager does not invoke this callback for any subsequent joins to the group.

The multicast group manager uses the following rule to determine when to invoke this callback for source-specific (s, g) joins:

* If this is the first client to inform the multicast group manager that there are receivers on an interface for a source and group, the multicast group manager invokes the
  **PMGM_JOIN_ALERT_CALLBACK** callback only for the client that owns the incoming interface towards the source "s".

This version of the Multicast Group Manager API supports only wildcard sources (*, g) or specific sources (s, g), not a range of sources. The same restriction applies to groups (that is, no group ranges are permitted).