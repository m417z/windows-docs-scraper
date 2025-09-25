NTSTATUS ObReferenceObjectByPointer(
  [in]           PVOID           Object,
  [in]           ACCESS_MASK     DesiredAccess,
  [in, optional] POBJECT_TYPE    ObjectType,
  [in]           KPROCESSOR_MODE AccessMode
);