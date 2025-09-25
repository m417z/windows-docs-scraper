typedef struct _DEVICE_COPY_OFFLOAD_DESCRIPTOR {
  DWORD     Version;
  DWORD     Size;
  DWORD     MaximumTokenLifetime;
  DWORD     DefaultTokenLifetime;
  DWORDLONG MaximumTransferSize;
  DWORDLONG OptimalTransferCount;
  DWORD     MaximumDataDescriptors;
  DWORD     MaximumTransferLengthPerDescriptor;
  DWORD     OptimalTransferLengthPerDescriptor;
  WORD      OptimalTransferLengthGranularity;
  BYTE      Reserved[2];
} DEVICE_COPY_OFFLOAD_DESCRIPTOR, *PDEVICE_COPY_OFFLOAD_DESCRIPTOR;