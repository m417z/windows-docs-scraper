ULONG StorPortPoFxPowerControl(
  [in]            PVOID         HwDeviceExtension,
                  PSTOR_ADDRESS Address,
  [in]            LPCGUID       PowerControlCode,
  [in, optional]  PVOID         InBuffer,
  [in]            SIZE_T        InBufferSize,
  [out, optional] PVOID         OutBuffer,
  [in]            SIZE_T        OutBufferSize,
  [out, optional] PSIZE_T       BytesReturned
);