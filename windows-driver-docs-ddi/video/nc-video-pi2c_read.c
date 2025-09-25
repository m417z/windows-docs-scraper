PI2C_READ Pi2cRead;

BOOLEAN Pi2cRead(
  [in]  IN PVOID HwDeviceExtension,
  [in]  IN PI2C_CALLBACKS I2CCallbacks,
  [out] OUT PUCHAR Buffer,
  [in]  IN ULONG Length
)
{...}