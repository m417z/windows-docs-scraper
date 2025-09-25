GPIO_CLIENT_PREPARE_CONTROLLER GpioClientPrepareController;

NTSTATUS GpioClientPrepareController(
  [in] WDFDEVICE Device,
  [in] PVOID Context,
  [in] WDFCMRESLIST ResourcesRaw,
  [in] WDFCMRESLIST ResourcesTranslated
)
{...}