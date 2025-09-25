ULONG StorPortInitializePoFxPower(
  [in]           PVOID             HwDeviceExtension,
  [in, optional] PSTOR_ADDRESS     Address,
  [in]           PSTOR_POFX_DEVICE Device,
  [in, out]      PBOOLEAN          D3ColdEnabled
);