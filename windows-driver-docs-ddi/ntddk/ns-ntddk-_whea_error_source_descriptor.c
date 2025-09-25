typedef struct _WHEA_ERROR_SOURCE_DESCRIPTOR {
  ULONG                   Length;
  ULONG                   Version;
  WHEA_ERROR_SOURCE_TYPE  Type;
  WHEA_ERROR_SOURCE_STATE State;
  ULONG                   MaxRawDataLength;
  ULONG                   NumRecordsToPreallocate;
  ULONG                   MaxSectionsPerRecord;
  ULONG                   ErrorSourceId;
  ULONG                   PlatformErrorSourceId;
  ULONG                   Flags;
  union {
    WHEA_XPF_MCE_DESCRIPTOR          XpfMceDescriptor;
    WHEA_XPF_CMC_DESCRIPTOR          XpfCmcDescriptor;
    WHEA_XPF_NMI_DESCRIPTOR          XpfNmiDescriptor;
    WHEA_IPF_MCA_DESCRIPTOR          IpfMcaDescriptor;
    WHEA_IPF_CMC_DESCRIPTOR          IpfCmcDescriptor;
    WHEA_IPF_CPE_DESCRIPTOR          IpfCpeDescriptor;
    WHEA_AER_ROOTPORT_DESCRIPTOR     AerRootportDescriptor;
    WHEA_AER_ENDPOINT_DESCRIPTOR     AerEndpointDescriptor;
    WHEA_AER_BRIDGE_DESCRIPTOR       AerBridgeDescriptor;
    WHEA_GENERIC_ERROR_DESCRIPTOR    GenErrDescriptor;
    WHEA_GENERIC_ERROR_DESCRIPTOR_V2 GenErrDescriptorV2;
    WHEA_DEVICE_DRIVER_DESCRIPTOR    DeviceDriverDescriptor;
  } Info;
} *PWHEA_ERROR_SOURCE_DESCRIPTOR, WHEA_ERROR_SOURCE_DESCRIPTOR;