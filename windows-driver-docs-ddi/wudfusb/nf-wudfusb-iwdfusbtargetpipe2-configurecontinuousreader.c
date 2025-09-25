HRESULT ConfigureContinuousReader(
  [in]           SIZE_T                                              TransferLength,
  [in]           SIZE_T                                              HeaderLength,
  [in]           SIZE_T                                              TrailerLength,
  [in]           UCHAR                                               NumPendingReads,
  [in, optional] IUnknown                                            *pMemoryCleanupCallbackInterface,
  [in]           IUsbTargetPipeContinuousReaderCallbackReadComplete  *pOnCompletion,
  [in, optional] PVOID                                               pCompletionContext,
  [in, optional] IUsbTargetPipeContinuousReaderCallbackReadersFailed *pOnFailure
);