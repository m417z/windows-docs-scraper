NTSTATUS IoWMIExecuteMethod(
  [in]      PVOID           DataBlockObject,
  [in]      PUNICODE_STRING InstanceName,
  [in]      ULONG           MethodId,
  [in]      ULONG           InBufferSize,
  [in, out] PULONG          OutBufferSize,
  [in, out] PUCHAR          InOutBuffer
);