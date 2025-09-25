# MgmDeleteGroupMembershipEntry function

## Description

The
**MgmDeleteGroupMembershipEntry** function notifies the multicast group manager that there are no more receivers present for the specified groups on the specified interface.

A multicast routing protocol calls this function after it is notified that there are no more receivers for a multicast group on an interface. The protocol must call this function to stop multicast data from being forwarded out over an interface.

## Parameters

### `hProtocol` [in]

Handle to the protocol obtained from a previous call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

### `dwSourceAddr` [in]

Specifies the source address from which to stop receiving multicast data. Specify zero to stop receiving data from all sources (a wildcard receiver for a group); otherwise, specify the IP address of the source or source network.

To specify a range of source addresses, specify the source network using *dwSourceAddr*, and specify a subnet mask using *dwSourceMask*.

### `dwSourceMask` [in]

Specifies the subnet mask that corresponds to *dwSourceAddr*. The *dwSourceAddr* and *dwSourceMask* parameters are used together to define a range of sources from which to stop receiving multicast data.

Specify zero for this parameter if zero was specified for *dwSourceAddr* (a wildcard receiver).

### `dwGroupAddr` [in]

Specifies the multicast group for which to stop receiving data. Specify zero to stop receiving all groups (a wildcard receiver); otherwise, specify the IP address of the group.

To specify a range of group addresses, specify the group address using *dwGroupAddr*, and specify a subnet mask using *dwGroupMask*.

### `dwGroupMask` [in]

Specifies the subnet mask that corresponds to *dwGroupAddr*. The *dwGroupAddr* and *dwGroupMask* parameters are used together to define a range of multicast groups.

Specify zero for this parameter if zero was specified for *dwGroupAddr* (a wildcard receiver).

### `dwIfIndex` [in]

Specifies the interface on which to delete the group membership. Multicast data for the specified groups are no longer forwarded out over this interface.

### `dwIfNextHopIPAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

### `dwFlags` [in]

Specifies any additional processing that must take place when the group membership is removed. Valid values are:

| Value | Meaning |
| --- | --- |
| **MGM_JOIN_STATE_FLAG** | Remove group membership for the specified source and group. Update any forwarding entries for the specified source group to reflect this change in group membership. |
| **MGM_FORWARD_STATE** | Remove the specified interface from the list of outgoing interfaces for the forwarding entry that corresponds to the specified source and group. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to a protocol, or the interface is owned by another protocol. |
| **ERROR_NOT_FOUND** | The specified interface was not found. |

## Remarks

This version of the MGM API supports only wildcard sources or specific sources, not a range of sources. The same restriction applies to groups (that is, no group ranges are permitted).

When this function is called, the multicast group manager may invoke the
[PMGM_PRUNE_ALERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_prune_alert_callback) callback to notify other routing protocols that no more receivers are present for the specified group.

## See also

[MgmAddGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmaddgroupmembershipentry)

[PMGM_PRUNE_ALERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_prune_alert_callback)