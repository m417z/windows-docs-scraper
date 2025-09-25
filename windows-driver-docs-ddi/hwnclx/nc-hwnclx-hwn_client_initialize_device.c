HWN_CLIENT_INITIALIZE_DEVICE HwnClientInitializeDevice;

NTSTATUS HwnClientInitializeDevice(
  [in] WDFDEVICE Device,
  [in] PVOID Context,
  [in] WDFCMRESLIST ResourcesRaw,
  [in] WDFCMRESLIST ResourcesTranslated
)
{...}