typedef union {
  NVME_CDW12_FEATURE_HOST_MEMORY_BUFFER HostMemoryBuffer;
  ULONG                                 AsUlong;
} NVME_CDW12_FEATURES, *PNVME_CDW12_FEATURES;