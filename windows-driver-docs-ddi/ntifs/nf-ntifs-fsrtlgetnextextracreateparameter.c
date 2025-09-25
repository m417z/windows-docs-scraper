NTSTATUS FsRtlGetNextExtraCreateParameter(
  [in]            PECP_LIST EcpList,
  [in, optional]  PVOID     CurrentEcpContext,
  [out, optional] LPGUID    NextEcpType,
  [out]           PVOID     *NextEcpContext,
  [out, optional] ULONG     *NextEcpContextSize
);