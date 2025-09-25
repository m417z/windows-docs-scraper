EVT_UCX_CONTROLLER_QUERY_USB_CAPABILITY EvtUcxControllerQueryUsbCapability;

NTSTATUS EvtUcxControllerQueryUsbCapability(
  [in]            UCXCONTROLLER UcxController,
  [in]            PGUID CapabilityType,
  [in]            ULONG OutputBufferLength,
  [out, optional] PVOID OutputBuffer,
  [out]           PULONG ResultLength
)
{...}