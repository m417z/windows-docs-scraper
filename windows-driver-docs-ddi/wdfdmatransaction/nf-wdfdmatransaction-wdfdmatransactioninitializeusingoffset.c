NTSTATUS WdfDmaTransactionInitializeUsingOffset(
  [in] WDFDMATRANSACTION   DmaTransaction,
  [in] PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
  [in] WDF_DMA_DIRECTION   DmaDirection,
  [in] PMDL                Mdl,
  [in] size_t              Offset,
  [in] size_t              Length
);