typedef union _DMA_ADAPTER_INFO {
  struct {
    ULONG               Version;
    DMA_ADAPTER_INFO_V1 V1;
  };
  struct {
    ULONGLONG Reserved;
    union {
      DMA_ADAPTER_INFO_CRASHDUMP Crashdump;
    };
  };
} DMA_ADAPTER_INFO, *PDMA_ADAPTER_INFO;