HRESULT GetFieldTypeAndOffsetWide(
  [in]            ULONG64 Module,
  [in]            ULONG   ContainerTypeId,
  [in]            PCWSTR  Field,
  [out, optional] PULONG  FieldTypeId,
  [out, optional] PULONG  Offset
);