typedef union {
  NVME_CDW14_FEATURE_HOST_MEMORY_BUFFER HostMemoryBuffer;
  ULONG                                 AsUlong;
} NVME_CDW14_FEATURES, *PNVME_CDW14_FEATURES;