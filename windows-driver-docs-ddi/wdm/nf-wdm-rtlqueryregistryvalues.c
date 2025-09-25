NTSYSAPI NTSTATUS RtlQueryRegistryValues(
  [in]           ULONG                     RelativeTo,
  [in]           PCWSTR                    Path,
  [in, out]      PRTL_QUERY_REGISTRY_TABLE QueryTable,
  [in, optional] PVOID                     Context,
  [in, optional] PVOID                     Environment
);