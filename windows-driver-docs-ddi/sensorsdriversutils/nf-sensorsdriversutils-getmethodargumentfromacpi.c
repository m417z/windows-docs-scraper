NTSTATUS GetMethodArgumentFromAcpi(
  WDFDEVICE Device,
  PSZ       MethodName,
  UCHAR     MethodNameLength,
  BYTE      *MethodArgument,
  ULONG     MethodArgumentLength
);