HRESULT GetFieldTypeAndOffset(
  [in]            ULONG64 Module,
  [in]            ULONG   ContainerTypeId,
  [in]            PCSTR   Field,
  [out, optional] PULONG  FieldTypeId,
  [out, optional] PULONG  Offset
);