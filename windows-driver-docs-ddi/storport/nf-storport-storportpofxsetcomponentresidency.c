ULONG StorPortPoFxSetComponentResidency(
  [in]           PVOID         HwDeviceExtension,
  [in, optional] PSTOR_ADDRESS Address,
  [in]           ULONG         Component,
  [in]           ULONGLONG     Residency
);