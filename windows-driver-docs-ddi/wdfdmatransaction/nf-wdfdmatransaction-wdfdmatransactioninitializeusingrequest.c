NTSTATUS WdfDmaTransactionInitializeUsingRequest(
  [in] WDFDMATRANSACTION   DmaTransaction,
  [in] WDFREQUEST          Request,
  [in] PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
  [in] WDF_DMA_DIRECTION   DmaDirection
);