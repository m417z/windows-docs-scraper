# DHCP_FORCE_FLAG enumeration

## Description

The **DHCP_FORCE_FLAG** enumeration defines the set of flags describing the force level of a DHCP subnet element deletion operation.

## Constants

### `DhcpFullForce`

The operation deletes all client records affected by the element, and then deletes the element.

### `DhcpNoForce`

The operation only deletes the subnet element, leaving intact any client records impacted by the change.

### `DhcpFailoverForce`

The operation deletes all client records affected by the element, and then deletes the element from the DHCP server. But it does not delete any registered DNS records associated with the deleted client records from the DNS server. This flag is only valid when passed to [DhcpDeleteSubnet](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdeletesubnet). Note that the minimum server OS requirement for this value is Windows Server 2012 R2 with KB 3100473 installed.

## See also

[DhcpRemoveSubnetElementV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremovesubnetelementv5)