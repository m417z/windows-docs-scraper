NTSTATUS FLTAPI FltAllocateExtraCreateParameterFromLookasideList(
  [in]           PFLT_FILTER                                    Filter,
  [in]           LPCGUID                                        EcpType,
  [in]           ULONG                                          SizeOfContext,
  [in]           FSRTL_ALLOCATE_ECP_FLAGS                       Flags,
  [in, optional] PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK CleanupCallback,
  [in, out]      PVOID                                          LookasideList,
  [out]          PVOID                                          *EcpContext
);