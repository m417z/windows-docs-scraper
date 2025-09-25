NTSTATUS FLTAPI FltRemoveExtraCreateParameter(
  [in]            PFLT_FILTER Filter,
  [in, out]       PECP_LIST   EcpList,
  [in]            LPCGUID     EcpType,
  [out]           PVOID       *EcpContext,
  [out, optional] ULONG       *EcpContextSize
);