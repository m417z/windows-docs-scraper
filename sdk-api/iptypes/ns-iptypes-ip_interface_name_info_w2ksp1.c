typedef struct ip_interface_name_info_w2ksp1 {
  ULONG Index;
  ULONG MediaType;
  UCHAR ConnectionType;
  UCHAR AccessType;
  GUID  DeviceGuid;
  GUID  InterfaceGuid;
} IP_INTERFACE_NAME_INFO_W2KSP1, *PIP_INTERFACE_NAME_INFO_W2KSP1;