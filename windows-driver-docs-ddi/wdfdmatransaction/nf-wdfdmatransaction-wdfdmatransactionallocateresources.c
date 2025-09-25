NTSTATUS WdfDmaTransactionAllocateResources(
  [in] WDFDMATRANSACTION   DmaTransaction,
  [in] WDF_DMA_DIRECTION   DmaDirection,
  [in] ULONG               RequiredMapRegisters,
  [in] PFN_WDF_RESERVE_DMA EvtReserveDmaFunction,
  [in] PVOID               EvtReserveDmaContext
);