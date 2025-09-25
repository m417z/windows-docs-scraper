EVT_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS EvtWdfIoWdmIrpForForwardProgress;

WDF_IO_FORWARD_PROGRESS_ACTION EvtWdfIoWdmIrpForForwardProgress(
  [in] WDFQUEUE Queue,
  [in] PIRP Irp
)
{...}