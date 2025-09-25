NTSTATUS WdfDmaTransactionInitialize(
  [in] WDFDMATRANSACTION   DmaTransaction,
  [in] PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
  [in] WDF_DMA_DIRECTION   DmaDirection,
  [in] PMDL                Mdl,
  [in] PVOID               VirtualAddress,
  [in] size_t              Length
);