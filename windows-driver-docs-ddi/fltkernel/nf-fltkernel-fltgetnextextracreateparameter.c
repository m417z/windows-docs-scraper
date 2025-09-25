NTSTATUS FLTAPI FltGetNextExtraCreateParameter(
  [in]            PFLT_FILTER Filter,
  [in]            PECP_LIST   EcpList,
  [in, optional]  PVOID       CurrentEcpContext,
  [out, optional] LPGUID      NextEcpType,
  [out, optional] PVOID       *NextEcpContext,
  [out, optional] ULONG       *NextEcpContextSize
);