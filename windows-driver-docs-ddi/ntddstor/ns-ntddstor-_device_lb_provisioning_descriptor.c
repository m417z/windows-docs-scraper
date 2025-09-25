typedef struct _DEVICE_LB_PROVISIONING_DESCRIPTOR {
  ULONG     Version;
  ULONG     Size;
  UCHAR     ThinProvisioningEnabled : 1;
  UCHAR     ThinProvisioningReadZeros : 1;
  UCHAR     AnchorSupported : 3;
  UCHAR     UnmapGranularityAlignmentValid : 1;
  UCHAR     GetFreeSpaceSupported : 1;
  UCHAR     MapSupported : 1;
  UCHAR     Reserved1[7];
  ULONGLONG OptimalUnmapGranularity;
  ULONGLONG UnmapGranularityAlignment;
  ULONG     MaxUnmapLbaCount;
  ULONG     MaxUnmapBlockDescriptorCount;
} DEVICE_LB_PROVISIONING_DESCRIPTOR, *PDEVICE_LB_PROVISIONING_DESCRIPTOR;