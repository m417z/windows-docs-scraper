NTSTATUS FLTAPI FltAllocateExtraCreateParameterList(
  [in]  PFLT_FILTER                  Filter,
  [in]  FSRTL_ALLOCATE_ECPLIST_FLAGS Flags,
  [out] PECP_LIST                    *EcpList
);