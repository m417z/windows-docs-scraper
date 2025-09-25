PI2C_WRITE Pi2cWrite;

BOOLEAN Pi2cWrite(
  [in] IN PVOID HwDeviceExtension,
  [in] IN PI2C_CALLBACKS I2CCallbacks,
  [in] IN PUCHAR Buffer,
  [in] IN ULONG Length
)
{...}