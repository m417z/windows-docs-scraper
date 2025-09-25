ULONG StorPortInvokeAcpiMethod(
  [in]            PVOID         HwDeviceExtension,
  [in, optional]  PSTOR_ADDRESS Address,
  [in]            ULONG         MethodName,
  [in, optional]  PVOID         InputBuffer,
  [in]            ULONG         InputBufferLength,
  [in, optional]  PVOID         OutputBuffer,
  [in]            ULONG         OutputBufferLength,
  [out, optional] PULONG        BytesReturned
);