typedef struct _MIB_IFSTACK_ROW {
  NET_IFINDEX HigherLayerInterfaceIndex;
  NET_IFINDEX LowerLayerInterfaceIndex;
} MIB_IFSTACK_ROW, *PMIB_IFSTACK_ROW;