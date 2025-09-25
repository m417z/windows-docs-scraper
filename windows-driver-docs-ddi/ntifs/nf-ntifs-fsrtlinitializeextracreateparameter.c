VOID FsRtlInitializeExtraCreateParameter(
  [in]           PECP_HEADER                                    Ecp,
  [in]           ULONG                                          EcpFlags,
  [in, optional] PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK CleanupCallback,
  [in]           ULONG                                          TotalSize,
  [in]           LPCGUID                                        EcpType,
  [in, optional] PVOID                                          ListAllocatedFrom
);