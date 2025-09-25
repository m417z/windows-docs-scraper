NTSTATUS WdfObjectQuery(
  [in]  WDFOBJECT  Object,
  [in]  const GUID *Guid,
  [in]  ULONG      QueryBufferLength,
  [out] PVOID      QueryBuffer
);