NTSTATUS FsRtlRemoveExtraCreateParameter(
  [in, out]       PECP_LIST EcpList,
  [in]            LPCGUID   EcpType,
  [out]           PVOID     *EcpContext,
  [out, optional] ULONG     *EcpContextSize
);