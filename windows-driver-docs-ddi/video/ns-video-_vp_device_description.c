typedef struct _VP_DEVICE_DESCRIPTION {
  BOOLEAN ScatterGather;
  BOOLEAN Dma32BitAddresses;
  BOOLEAN Dma64BitAddresses;
  ULONG   MaximumLength;
} VP_DEVICE_DESCRIPTION, *PVP_DEVICE_DESCRIPTION;