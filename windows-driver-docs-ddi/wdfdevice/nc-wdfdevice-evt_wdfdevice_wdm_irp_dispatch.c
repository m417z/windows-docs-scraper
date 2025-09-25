EVT_WDFDEVICE_WDM_IRP_DISPATCH EvtWdfdeviceWdmIrpDispatch;

NTSTATUS EvtWdfdeviceWdmIrpDispatch(
  [in]      WDFDEVICE Device,
  [in]      UCHAR MajorFunction,
  [in]      UCHAR MinorFunction,
  [in]      ULONG Code,
  [in]      WDFCONTEXT DriverContext,
  [in, out] PIRP Irp,
  [in]      WDFCONTEXT DispatchContext
)
{...}