typedef struct _DMA_ADAPTER {
  USHORT          Version;
  USHORT          Size;
  PDMA_OPERATIONS DmaOperations;
} *PADAPTER_OBJECT, DMA_ADAPTER, *PDMA_ADAPTER;