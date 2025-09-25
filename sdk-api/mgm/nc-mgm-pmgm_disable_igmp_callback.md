# PMGM_DISABLE_IGMP_CALLBACK callback function

## Description

The
**PMGM_DISABLE_IGMP_CALLBACK** callback is a call into IGMP to notify it that a routing protocol is taking or releasing ownership of an interface on which IGMP is enabled.

When this callback is invoked, IGMP should stop adding and deleting group memberships on the specified interface.

## Parameters

### `dwIfIndex` [in]

Specifies the interface on which to disable IGMP.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## See also

[PMGM_ENABLE_IGMP_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_enable_igmp_callback)