VOID NdisWriteErrorLogEntry(
  [in] NDIS_HANDLE     NdisAdapterHandle,
  [in] NDIS_ERROR_CODE ErrorCode,
  [in] ULONG           NumberOfErrorValues,
       ...             
);