typedef struct _D3DKMT_QUERYSTATSTICS_REFERENCE_DMA_BUFFER {
  ULONG NbCall;
  ULONG NbAllocationsReferenced;
  ULONG MaxNbAllocationsReferenced;
  ULONG NbNULLReference;
  ULONG NbWriteReference;
  ULONG NbRenamedAllocationsReferenced;
  ULONG NbIterationSearchingRenamedAllocation;
  ULONG NbLockedAllocationReferenced;
  ULONG NbAllocationWithValidPrepatchingInfoReferenced;
  ULONG NbAllocationWithInvalidPrepatchingInfoReferenced;
  ULONG NbDMABufferSuccessfullyPrePatched;
  ULONG NbPrimariesReferencesOverflow;
  ULONG NbAllocationWithNonPreferredResources;
  ULONG NbAllocationInsertedInMigrationTable;
} D3DKMT_QUERYSTATSTICS_REFERENCE_DMA_BUFFER;