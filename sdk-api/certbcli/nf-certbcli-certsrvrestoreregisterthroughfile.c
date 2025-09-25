HRESULT CERTBCLI_API CertSrvRestoreRegisterThroughFile(
  [in]           HCSBC            hbc,
  [in, optional] WCHAR const      *pwszCheckPointFilePath,
  [in, optional] WCHAR const      *pwszLogPath,
  [in, optional] CSEDB_RSTMAPW [] rgrstmap,
  [in]           LONG             crstmap,
  [in, optional] WCHAR const      *pwszBackupLogPath,
  [in]           ULONG            genLow,
  [in]           ULONG            genHigh
);