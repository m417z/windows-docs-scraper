typedef struct _NDIS_SYSTEM_PROCESSOR_INFO {
  NDIS_OBJECT_HEADER    Header;
  ULONG                 Flags;
  NDIS_PROCESSOR_VENDOR ProcessorVendor;
  ULONG                 NumPhysicalPackages;
  ULONG                 NumCores;
  ULONG                 NumCoresPerPhysicalPackage;
  ULONG                 MaxHyperThreadingCpusPerCore;
  ULONG                 RssBaseCpu;
  ULONG                 RssCpuCount;
  PUCHAR                RssProcessors;
  NDIS_PROCESSOR_INFO   CpuInfo[MAXIMUM_PROC_PER_GROUP];
} NDIS_SYSTEM_PROCESSOR_INFO, *PNDIS_SYSTEM_PROCESSOR_INFO;