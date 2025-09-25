NTSTATUS IoWMIQuerySingleInstanceMultiple(
  [in]            PVOID           *DataBlockObjectList,
  [in]            PUNICODE_STRING InstanceNames,
  [in]            ULONG           ObjectCount,
  [in, out]       PULONG          InOutBufferSize,
  [out, optional] PVOID           OutBuffer
);