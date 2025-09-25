NTSTATUS PoCreatePowerRequest(
  [out] PVOID                   *PowerRequest,
  [in]  PDEVICE_OBJECT          DeviceObject,
  [in]  PCOUNTED_REASON_CONTEXT Context
);