EVT_SERCX_CONTROL EvtSercxControl;

NTSTATUS EvtSercxControl(
  [in] WDFDEVICE Device,
  [in] WDFREQUEST Request,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength,
  [in] ULONG IoControlCode
)
{...}