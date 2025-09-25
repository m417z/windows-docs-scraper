# CLUSTER_NETWORK_ROLE enumeration

## Description

Describes the role a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) plays in the
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The
[network role](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks-role) and
[DefaultNetworkRole](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusters-defaultnetworkrole) common properties use
this enumeration. This is a bitmask.

## Constants

### `ClusterNetworkRoleNone:0`

The network is not used by the cluster.

### `ClusterNetworkRoleInternalUse:0x00000001`

The network is used to carry internal cluster communication.

### `ClusterNetworkRoleClientAccess:0x00000002`

Not supported.

### `ClusterNetworkRoleInternalAndClient:0x00000003`

The network is used to connect client systems and to carry internal cluster communication.

## See also

[DefaultNetworkRole](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusters-defaultnetworkrole)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[Network Role](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks-role)