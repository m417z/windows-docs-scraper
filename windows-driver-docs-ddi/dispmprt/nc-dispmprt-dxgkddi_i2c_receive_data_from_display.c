DXGKDDI_I2C_RECEIVE_DATA_FROM_DISPLAY DxgkddiI2cReceiveDataFromDisplay;

NTSTATUS DxgkddiI2cReceiveDataFromDisplay(
  [in]  PVOID MiniportDeviceContext,
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID VidPnTargetId,
  [in]  ULONG SevenBitI2CAddress,
  [in]  ULONG Flags,
  [in]  ULONG DataLength,
  [out] PVOID Data
)
{...}