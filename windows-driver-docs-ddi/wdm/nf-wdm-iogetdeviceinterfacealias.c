NTSTATUS IoGetDeviceInterfaceAlias(
  [in]  PUNICODE_STRING SymbolicLinkName,
  [in]  const GUID      *AliasInterfaceClassGuid,
  [out] PUNICODE_STRING AliasSymbolicLinkName
);