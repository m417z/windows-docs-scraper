typedef struct _DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION {
  DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_TYPE ConfigType;
  union {
    struct {
      PHYSICAL_ADDRESS MinimumAddress;
      PHYSICAL_ADDRESS MaximumAddress;
    } LogicalAddressLimits;
    struct {
      ULONGLONG Offset;
      ULONG     Length;
    } SubSection;
    DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_ACCESS_TYPE HardwareAccessType;
    ULONGLONG                                            Reserved[4];
  };
} DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION, *PDMA_COMMON_BUFFER_EXTENDED_CONFIGURATION;