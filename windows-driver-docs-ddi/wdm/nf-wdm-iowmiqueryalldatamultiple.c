NTSTATUS IoWMIQueryAllDataMultiple(
  [in]            PVOID  *DataBlockObjectList,
  [in]            ULONG  ObjectCount,
  [in, out]       PULONG InOutBufferSize,
  [out, optional] PVOID  OutBuffer
);