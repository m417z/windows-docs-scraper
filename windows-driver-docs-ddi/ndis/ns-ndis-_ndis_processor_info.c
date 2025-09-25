typedef struct _NDIS_PROCESSOR_INFO {
  ULONG CpuNumber;
  ULONG PhysicalPackageId;
  ULONG CoreId;
  ULONG HyperThreadID;
} NDIS_PROCESSOR_INFO, *PNDIS_PROCESSOR_INFO;