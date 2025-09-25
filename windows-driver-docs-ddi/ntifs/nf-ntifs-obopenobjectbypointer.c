NTSTATUS ObOpenObjectByPointer(
  [in]           PVOID           Object,
  [in]           ULONG           HandleAttributes,
  [in, optional] PACCESS_STATE   PassedAccessState,
  [in]           ACCESS_MASK     DesiredAccess,
  [in, optional] POBJECT_TYPE    ObjectType,
  [in]           KPROCESSOR_MODE AccessMode,
  [out]          PHANDLE         Handle
);