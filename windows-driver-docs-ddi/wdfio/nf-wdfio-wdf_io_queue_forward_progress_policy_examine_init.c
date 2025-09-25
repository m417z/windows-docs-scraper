VOID WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT(
  [out] PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY   Policy,
  [in]  ULONG                                   TotalForwardProgressRequests,
  [in]  PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS EvtIoWdmIrpForForwardProgress
);