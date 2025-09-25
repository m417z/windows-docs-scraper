HRESULT CERTBCLI_API CertSrvRestoreRegisterW(
  [in] HCSBC            hbc,
  [in] WCHAR const      *pwszCheckPointFilePath,
  [in] WCHAR const      *pwszLogPath,
  [in] CSEDB_RSTMAPW [] rgrstmap,
  [in] LONG             crstmap,
  [in] WCHAR const      *pwszBackupLogPath,
  [in] ULONG            genLow,
  [in] ULONG            genHigh
);