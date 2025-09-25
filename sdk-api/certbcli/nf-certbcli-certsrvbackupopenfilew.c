HRESULT CERTBCLI_API CertSrvBackupOpenFileW(
  [in]  HCSBC         hbc,
  [in]  WCHAR const   *pwszAttachmentName,
  [in]  DWORD         cbReadHintSize,
  [out] LARGE_INTEGER *pliFileSize
);