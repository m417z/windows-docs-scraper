typedef enum CLUSTER_NETWORK_ROLE {
  ClusterNetworkRoleNone = 0,
  ClusterNetworkRoleInternalUse = 0x00000001,
  ClusterNetworkRoleClientAccess = 0x00000002,
  ClusterNetworkRoleInternalAndClient = 0x00000003
} ;