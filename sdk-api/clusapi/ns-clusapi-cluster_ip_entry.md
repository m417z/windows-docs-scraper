# CLUSTER_IP_ENTRY structure

## Description

Describes an IP address for a cluster.

## Members

### `lpszIpAddress`

A **NULL**-terminated Unicode string containing a valid IPv4 or IPv6 numeric network
address.

### `dwPrefixLength`

Specifies the number of bits in the subnet mask, for example 24 for an IPv4 netmask of 255.255.255.0.

## Remarks

To specify a DHCP address, use the network identifier (all bits in the subnet set to 0) and the subnet prefix
length. For example, if the DHCP server hands out addresses in the 192.168.1.0/24 address block (from 192.168.1.0
through 192.168.1.255), specify "192.168.1.0" for the **lpszIpAddress**
member and 24 for the **dwPrefixLength** member.

A pointer to an array of **CLUSTER_IP_ENTRY**
structures is passed in the **pIpEntries** member of the
[CREATE_CLUSTER_CONFIG](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-create_cluster_config) structure, which is in turn
passed as the *pConfig* parameter of the
[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster) function.

## See also

[CREATE_CLUSTER_CONFIG](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-create_cluster_config)

[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster)

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)