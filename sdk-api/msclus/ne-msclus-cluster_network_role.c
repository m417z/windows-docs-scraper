typedef enum CLUSTER_NETWORK_ROLE {
  ClusterNetworkRoleNone = 0,
  ClusterNetworkRoleInternalUse = 0x1,
  ClusterNetworkRoleClientAccess = 0x2,
  ClusterNetworkRoleInternalAndClient = 0x3
} ;