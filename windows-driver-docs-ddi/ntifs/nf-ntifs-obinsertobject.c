NTSTATUS ObInsertObject(
  PVOID         Object,
  PACCESS_STATE PassedAccessState,
  ACCESS_MASK   DesiredAccess,
  ULONG         ObjectPointerBias,
  PVOID         *NewObject,
  PHANDLE       Handle
);