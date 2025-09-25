BOOLEAN WdfDmaTransactionDmaCompletedFinal(
  [in]  WDFDMATRANSACTION DmaTransaction,
  [in]  size_t            FinalTransferredLength,
  [out] NTSTATUS          *Status
);