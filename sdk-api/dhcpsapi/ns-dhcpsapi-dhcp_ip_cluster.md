# DHCP_IP_CLUSTER structure

## Description

The **DHCP_IP_CLUSTER** structure defines the address and mast for a network cluster.

## Members

### `ClusterAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IP address of the cluster.

### `ClusterMask`

Specifies the mask value for a cluster. This value should be set to 0xFFFFFFFF if the cluster is full.