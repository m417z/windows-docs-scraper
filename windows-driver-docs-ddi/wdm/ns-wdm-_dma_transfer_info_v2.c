typedef struct _DMA_TRANSFER_INFO_V2 {
  ULONG MapRegisterCount;
  ULONG ScatterGatherElementCount;
  ULONG ScatterGatherListSize;
  ULONG LogicalPageCount;
} DMA_TRANSFER_INFO_V2, *PDMA_TRANSFER_INFO_V2;