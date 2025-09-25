# PMGM_ENABLE_IGMP_CALLBACK callback function

## Description

The
**PMGM_ENABLE_IGMP_CALLBACK** callback is a call into IGMP to notify it that a routing protocol has finished taking or releasing ownership of an interface.

When this callback is invoked, IGMP should add all its group memberships on the specified interface using calls to the
[MgmAddGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmaddgroupmembershipentry) function.

## Parameters

### `dwIfIndex` [in]

Specifies the index of the interface on which to enable IGMP.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## Remarks

IGMP must not add group memberships in the context of this callback. The multicast group manager and IGMP become deadlocked.

## See also

[PMGM_DISABLE_IGMP_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_disable_igmp_callback)