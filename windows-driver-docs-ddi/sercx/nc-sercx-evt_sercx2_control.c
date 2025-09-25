EVT_SERCX2_CONTROL EvtSercx2Control;

NTSTATUS EvtSercx2Control(
  [in] WDFDEVICE Device,
  [in] WDFREQUEST Request,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength,
  [in] ULONG IoControlCode
)
{...}