DXGKDDI_I2C_TRANSMIT_DATA_TO_DISPLAY DxgkddiI2cTransmitDataToDisplay;

NTSTATUS DxgkddiI2cTransmitDataToDisplay(
  [in] PVOID MiniportDeviceContext,
  [in] D3DDDI_VIDEO_PRESENT_TARGET_ID VidPnTargetId,
  [in] ULONG SevenBitI2CAddress,
  [in] ULONG DataLength,
  [in] const VOID *Data
)
{...}