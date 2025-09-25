NTSTATUS WdfDmaTransactionCreate(
  [in]           WDFDMAENABLER          DmaEnabler,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          WDFDMATRANSACTION      *DmaTransaction
);