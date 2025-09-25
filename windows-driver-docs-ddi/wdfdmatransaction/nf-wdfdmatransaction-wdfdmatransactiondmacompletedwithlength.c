BOOLEAN WdfDmaTransactionDmaCompletedWithLength(
  [in]  WDFDMATRANSACTION DmaTransaction,
  [in]  size_t            TransferredLength,
  [out] NTSTATUS          *Status
);