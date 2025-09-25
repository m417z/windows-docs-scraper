NTSTATUS IoWMISuggestInstanceName(
  [in, optional] PDEVICE_OBJECT  PhysicalDeviceObject,
  [in, optional] PUNICODE_STRING SymbolicLinkName,
  [in]           BOOLEAN         CombineNames,
  [out]          PUNICODE_STRING SuggestedInstanceName
);