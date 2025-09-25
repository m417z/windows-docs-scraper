BOOT_DRIVER_CALLBACK_FUNCTION BootDriverCallbackFunction;

VOID BootDriverCallbackFunction(
  PVOID CallbackContext,
  BDCB_CALLBACK_TYPE Classification,
  PBDCB_IMAGE_INFORMATION ImageInformation
)
{...}