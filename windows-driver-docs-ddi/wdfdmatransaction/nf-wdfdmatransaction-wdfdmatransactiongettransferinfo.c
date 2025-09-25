VOID WdfDmaTransactionGetTransferInfo(
  [in]            WDFDMATRANSACTION DmaTransaction,
  [out, optional] ULONG             *MapRegisterCount,
  [out, optional] ULONG             *ScatterGatherElementCount
);