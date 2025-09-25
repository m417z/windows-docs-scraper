# MgmAddGroupMembershipEntry function

## Description

The
**MgmAddGroupMembershipEntry** function notifies the multicast group manager that there are new receivers for the specified groups on the specified interface. The receivers can restrict the set of sources from which they should receive multicast data by specifying a source range.

A multicast routing protocol calls this function when it is notified that there are receivers for a multicast group on an interface. The protocol must call this function so that multicast data can be forwarded out over an interface.

## Parameters

### `hProtocol` [in]

Handle to the protocol obtained from a previous call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

### `dwSourceAddr` [in]

Specifies the source address from which to receive multicast data. Specify zero to receive data from all sources (a wildcard receiver for a group); otherwise, specify the IP address of the source or source network.

To specify a range of source addresses, specify the source network using *dwSourceAddr*, and specify a subnet mask using *dwSourceMask*.

### `dwSourceMask` [in]

Specifies the subnet mask that corresponds to *dwSourceAddr*. The *dwSourceAddr* and *dwSourceMask* parameters are used together to define a range of sources from which to receive multicast data.

Specify zero for this parameter if zero was specified for *dwSourceAddr* (a wildcard receiver).

### `dwGroupAddr` [in]

Specifies the multicast group for which to receive data. Specify zero to receive all groups (a wildcard receiver); otherwise, specify the IP address of the group.

To specify a range of group addresses, specify the group address using *dwGroupAddr*, and specify a subnet mask using *dwGroupMask*.

### `dwGroupMask` [in]

Specifies the subnet mask that corresponds to *dwGroupAddr*. The *dwGroupAddr* and *dwGroupMask* parameters are used together to define a range of multicast groups.

Specify zero for this parameter if zero was specified for *dwGroupAddr* (a wildcard receiver).

### `dwIfIndex` [in]

Specifies the interface on which to add the group membership. Multicast data for the specified groups will be forwarded out over this interface.

### `dwIfNextHopIPAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

### `dwFlags` [in]

Specifies any additional processing that must take place when the group membership is added. Valid values are:

| Value | Meaning |
| --- | --- |
| **MGM_JOIN_STATE_FLAG** | Add group membership for the specified source and group. Update any forwarding entries for the specified source group to reflect this change in group membership. |
| **MGM_FORWARD_STATE** | Add the specified interface to the list of outgoing interfaces for the forwarding entry that corresponds to the specified source and group. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to the protocol. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory to complete this operation. |

## Remarks

This version of the MGM API supports only wildcard sources or specific sources, not a range of sources. The same restriction applies to groups, that is, no group ranges are permitted.

When this function is called, the multicast group manager may invoke the
[PMGM_JOIN_ALERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_join_alert_callback) callback to notify other routing protocols that there are new receivers for the specified group.

## See also

[MgmDeleteGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmdeletegroupmembershipentry)

[PMGM_JOIN_ALERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_join_alert_callback)