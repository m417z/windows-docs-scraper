PFNKSPINSETDEVICESTATE Pfnkspinsetdevicestate;

NTSTATUS Pfnkspinsetdevicestate(
  [in] PKSPIN Pin,
  [in] KSSTATE ToState,
  [in] KSSTATE FromState
)
{...}