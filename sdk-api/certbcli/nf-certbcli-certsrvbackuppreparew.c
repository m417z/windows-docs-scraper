HRESULT CERTBCLI_API CertSrvBackupPrepareW(
  [in]  WCHAR const *pwszServerName,
  [in]  ULONG       grbitJet,
  [in]  ULONG       dwBackupFlags,
  [out] HCSBC       *phbc
);