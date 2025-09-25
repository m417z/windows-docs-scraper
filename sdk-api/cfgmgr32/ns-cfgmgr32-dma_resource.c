typedef struct DMA_Resource_s {
  DMA_DES   DMA_Header;
  DMA_RANGE DMA_Data[ANYSIZE_ARRAY];
} DMA_RESOURCE, *PDMA_RESOURCE;