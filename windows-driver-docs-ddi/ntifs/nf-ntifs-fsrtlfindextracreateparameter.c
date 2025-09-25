NTSTATUS FsRtlFindExtraCreateParameter(
  [in]            PECP_LIST EcpList,
  [in]            LPCGUID   EcpType,
  [out, optional] PVOID     *EcpContext,
  [out, optional] ULONG     *EcpContextSize
);