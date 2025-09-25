typedef union {
  NVME_CDW15_FEATURE_HOST_MEMORY_BUFFER HostMemoryBuffer;
  ULONG                                 AsUlong;
} NVME_CDW15_FEATURES, *PNVME_CDW15_FEATURES;