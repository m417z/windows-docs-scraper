typedef struct _NDIS_MINIPORT_INIT_PARAMETERS {
  NDIS_OBJECT_HEADER                   Header;
  ULONG                                Flags;
  PNDIS_RESOURCE_LIST                  AllocatedResources;
  NDIS_HANDLE                          IMDeviceInstanceContext;
  NDIS_HANDLE                          MiniportAddDeviceContext;
  NET_IFINDEX                          IfIndex;
  NET_LUID                             NetLuid;
  PNDIS_PORT_AUTHENTICATION_PARAMETERS DefaultPortAuthStates;
  PNDIS_PCI_DEVICE_CUSTOM_PROPERTIES   PciDeviceCustomProperties;
} NDIS_MINIPORT_INIT_PARAMETERS, *PNDIS_MINIPORT_INIT_PARAMETERS;