typedef struct _DEVICE_COPY_OFFLOAD_DESCRIPTOR {
  ULONG     Version;
  ULONG     Size;
  ULONG     MaximumTokenLifetime;
  ULONG     DefaultTokenLifetime;
  ULONGLONG MaximumTransferSize;
  ULONGLONG OptimalTransferCount;
  ULONG     MaximumDataDescriptors;
  ULONG     MaximumTransferLengthPerDescriptor;
  ULONG     OptimalTransferLengthPerDescriptor;
  USHORT    OptimalTransferLengthGranularity;
  UCHAR     Reserved[2];
} DEVICE_COPY_OFFLOAD_DESCRIPTOR, *PDEVICE_COPY_OFFLOAD_DESCRIPTOR;