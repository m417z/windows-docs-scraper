ULONG StorPortPoFxIdleComponent(
  [in]           PVOID               HwDeviceExtension,
  [in, optional] PSTOR_ADDRESS       Address,
  [in, optional] PSCSI_REQUEST_BLOCK Srb,
  [in]           ULONG               Component,
  [in]           ULONG               Flags
);