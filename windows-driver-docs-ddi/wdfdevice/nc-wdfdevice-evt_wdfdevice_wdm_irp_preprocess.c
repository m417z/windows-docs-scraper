EVT_WDFDEVICE_WDM_IRP_PREPROCESS EvtWdfdeviceWdmIrpPreprocess;

NTSTATUS EvtWdfdeviceWdmIrpPreprocess(
  [in]      WDFDEVICE Device,
  [in, out] PIRP Irp
)
{...}