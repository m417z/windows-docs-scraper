NTSTATUS IoWMIQuerySingleInstance(
  [in]            PVOID           DataBlockObject,
  [in]            PUNICODE_STRING InstanceName,
  [in, out]       PULONG          InOutBufferSize,
  [out, optional] PVOID           OutBuffer
);