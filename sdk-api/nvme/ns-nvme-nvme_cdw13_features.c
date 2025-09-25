typedef union {
  NVME_CDW13_FEATURE_HOST_MEMORY_BUFFER HostMemoryBuffer;
  ULONG                                 AsUlong;
} NVME_CDW13_FEATURES, *PNVME_CDW13_FEATURES;