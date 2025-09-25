typedef struct _DEVICE_LB_PROVISIONING_DESCRIPTOR {
  DWORD     Version;
  DWORD     Size;
  BYTE      ThinProvisioningEnabled : 1;
  BYTE      ThinProvisioningReadZeros : 1;
  BYTE      AnchorSupported : 3;
  BYTE      UnmapGranularityAlignmentValid : 1;
  BYTE      GetFreeSpaceSupported : 1;
  BYTE      MapSupported : 1;
  BYTE      Reserved1[7];
  DWORDLONG OptimalUnmapGranularity;
  DWORDLONG UnmapGranularityAlignment;
  DWORD     MaxUnmapLbaCount;
  DWORD     MaxUnmapBlockDescriptorCount;
} DEVICE_LB_PROVISIONING_DESCRIPTOR, *PDEVICE_LB_PROVISIONING_DESCRIPTOR;