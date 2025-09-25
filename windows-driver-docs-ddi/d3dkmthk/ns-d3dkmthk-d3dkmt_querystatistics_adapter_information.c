typedef struct _D3DKMT_QUERYSTATISTICS_ADAPTER_INFORMATION {
  ULONG                                            NbSegments;
  ULONG                                            NodeCount;
  ULONG                                            VidPnSourceCount;
  ULONG                                            VSyncEnabled;
  ULONG                                            TdrDetectedCount;
  D3DKMT_ALIGN64 LONGLONG                          ZeroLengthDmaBuffers;
  D3DKMT_ALIGN64 ULONGLONG                         RestartedPeriod;
  D3DKMT_QUERYSTATSTICS_REFERENCE_DMA_BUFFER       ReferenceDmaBuffer;
  D3DKMT_QUERYSTATSTICS_RENAMING                   Renaming;
  D3DKMT_QUERYSTATSTICS_PREPRATION                 Preparation;
  D3DKMT_QUERYSTATSTICS_PAGING_FAULT               PagingFault;
  D3DKMT_QUERYSTATSTICS_PAGING_TRANSFER            PagingTransfer;
  D3DKMT_QUERYSTATSTICS_SWIZZLING_RANGE            SwizzlingRange;
  D3DKMT_QUERYSTATSTICS_LOCKS                      Locks;
  D3DKMT_QUERYSTATSTICS_ALLOCATIONS                Allocations;
  D3DKMT_QUERYSTATSTICS_TERMINATIONS               Terminations;
  D3DKMT_QUERYSTATISTICS_ADAPTER_INFORMATION_FLAGS Flags;
#if ...
  D3DKMT_ALIGN64 UINT64                            Reserved[7];
#else
  D3DKMT_ALIGN64 UINT64                            Reserved[8];
#endif
} D3DKMT_QUERYSTATISTICS_ADAPTER_INFORMATION;