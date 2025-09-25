typedef enum CLUSTER_NETINTERFACE_STATE {
  ClusterNetInterfaceStateUnknown = -1,
  ClusterNetInterfaceUnavailable,
  ClusterNetInterfaceFailed,
  ClusterNetInterfaceUnreachable,
  ClusterNetInterfaceUp
} ;